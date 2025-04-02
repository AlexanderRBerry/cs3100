/* 
    CS 3100 Lab 5 - by Alexander Berry
*/
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>
#include "dininglib.h"

// A lock used in critical sections
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
// Boolean to determine when to end threads
int bContinue = 1;
// Number of philosophers
int numPhilosophers;

// Executes the dining philosophers challenge
void* myFunc(void* arg){
    // Convert philosopherNumber back into an int
    int philosopherNumber = *(int*)arg; 
    // Ensure wrap around
    int rightChopstick;
    if((philosopherNumber + 1) == numPhilosophers){
        rightChopstick = 0;
    }
    else{
        rightChopstick = philosopherNumber + 1;
    }

    dpAddPhilosopher(philosopherNumber);
    // Thread loop
    while(bContinue) {
        /*******************Critical Areas Start *******************/
        // Acquire lock
        pthread_mutex_lock(&lock);
        // Reserve left chopstick. If successful reverse right chopstick
        if(dpReserveChopstick(philosopherNumber) == 0){
            if(dpReserveChopstick(rightChopstick) == 0){
                pthread_mutex_unlock(&lock);
                dpDine();
                pthread_mutex_lock(&lock);
                dpReleaseChopstick(philosopherNumber);
                dpReleaseChopstick(rightChopstick);
                pthread_mutex_unlock(&lock);
                dpThink();
                continue;
            }
            // If right chopstick wasn't reserved release the left
            else{
                dpReleaseChopstick(philosopherNumber);
            }
        }
        // Unable to reserve both chopsticks
        pthread_mutex_unlock(&lock);
        dpShortWait();
    }
        /*******************Critical Areas End**********************/
    return NULL;
}

int main(int argc, char **argv){
    numPhilosophers = atoi(argv[1]);
    int numSeconds = atoi(argv[2]);

    if(dpInitialize(numPhilosophers, numSeconds) == -1){
        perror("Failure to initialize");
        exit(1);
    }

    // Create num philosopher threads
    pthread_t threads[numPhilosophers];
    // Thread attributes
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    for (int i = 0; i < numPhilosophers; i++) {
        int* philosopher_id = malloc(sizeof(int)); 
        *philosopher_id = i;
        pthread_create(&threads[i], NULL, myFunc, philosopher_id);
    }
    // Sleeps parent thread for num Seconds
    dpCommence();
    bContinue = 0;
    // Cancel threads
    for(int i = 0; i < numPhilosophers; i++){
        pthread_cancel(threads[i]);
    }
    dpTerminate();

    return 0;
}