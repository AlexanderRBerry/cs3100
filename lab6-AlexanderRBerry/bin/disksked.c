/* 
    CS 3100 Lab 6 - by Alexander Berry
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I am calling this function in order to return a copy.
// This is a function provided on most POSIX systems, but doesn't seem to be available here.
char* strdup(const char* src) {
    char* dest = malloc(strlen(src) + 1);
    strcpy(dest, src);
    return dest;
}

// This function simply makes a copy of argv so that argv is not directly modified in other functions.
char** copyArgv(char** originalArgv, int argc) {
    char** copy = (char**)malloc((argc + 1) * sizeof(char*)); 
    if (!copy) {
        fprintf(stderr, "Memory allocation failed for argv copy\n");
        exit(1);
    }

    for (int i = 0; i < argc; i++) {
        copy[i] = (char*)malloc(strlen(originalArgv[i]) + 1);
        if (!copy[i]) {
            fprintf(stderr, "Memory allocation failed for argv[%d]\n", i);
            exit(1);
        }
        strcpy(copy[i], originalArgv[i]);
    }

    copy[argc] = NULL; 
    return copy;
}


// sprintf formats strings and stores it in a buffer.
// the first argument is the buffer 
// the second is the format of the string. "Hello %s!" %s is a string %d is an integer
// The next arguments are what will take place of placeholders like %s maybe "World"


// First Come First Serve implementation
char* FCFS(char ** argv){
    int total = 0;
    int distance = 0;
    char buffer[1024];
    sprintf(buffer, "FCFS: Start:%s ", argv[1]);
    for(int i = 1; i < 9; i++){
        distance = abs(atoi(argv[i]) - atoi(argv[i + 1]));
        total += distance;
        sprintf(buffer + strlen(buffer), "%s:%d ", argv[i + 1], distance);
    }
    sprintf(buffer + strlen(buffer), "Total:%d\n", total);
    return strdup(buffer);
}


// Shortest Seek Time First implementation
char* SSTF(char** argv, int argc) {
    int total = 0;
    int tracks[8];
    int visited[8] = {0};  // Keeps track of visited tracks
    int currentTrack = atoi(argv[1]);  // Start track
    char buffer[1024];

    sprintf(buffer, "SSTF: Start:%d ", currentTrack);

    // Convert track numbers to integers
    for (int i = 0; i < 8; i++) {
        tracks[i] = atoi(argv[i + 2]);
    }

    // Process tracks one by one, always moving to the closest next track
    for (int step = 0; step < 8; step++) {
        int minDist = __INT_MAX__; // Large initial value
        int minIndex = -1;

        // Find the closest unvisited track
        for (int i = 0; i < 8; i++) {
            if (!visited[i]) {
                int dist = abs(currentTrack - tracks[i]);
                if (dist < minDist) {
                    minDist = dist;
                    minIndex = i;
                }
            }
        }

        // Move to this closest track
        if (minIndex != -1) {
            visited[minIndex] = 1;  // Mark as visited
            total += minDist;
            sprintf(buffer + strlen(buffer), "%d:%d ", tracks[minIndex], minDist);
            currentTrack = tracks[minIndex];  // Update current position
        }
    }

    sprintf(buffer + strlen(buffer), "Total:%d\n", total);
    return strdup(buffer);
}


// C-Scan implementation
char* C_SCAN(char** argv) {
    int total = 0;
    int tracks[8];
    int currentTrack = atoi(argv[1]);
    char buffer[1024];
    sprintf(buffer, "C_SCAN: Start:%d ", currentTrack);

    // Convert track numbers to integers
    for (int i = 0; i < 8; i++) {
        tracks[i] = atoi(argv[i + 2]);
    }

    // Sort the tracks in ascending order
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (tracks[i] > tracks[j]) {
                int temp = tracks[i];
                tracks[i] = tracks[j];
                tracks[j] = temp;
            }
        }
    }

    // Find the index of the first track >= currentTrack
    int startIndex = 0;
    while (startIndex < 8 && tracks[startIndex] < currentTrack) {
        startIndex++;
    }

    // Move right first (higher numbered tracks)
    int prevTrack = currentTrack;
    for (int i = startIndex; i < 8; i++) {
        int distance = abs(prevTrack - tracks[i]);
        total += distance;
        sprintf(buffer + strlen(buffer), "%d:%d ", tracks[i], distance);
        prevTrack = tracks[i];
    }

    // Move left **(descending order of lower tracks)**
    for (int i = startIndex - 1; i >= 0; i--) {
        int distance = abs(prevTrack - tracks[i]);
        total += distance;
        sprintf(buffer + strlen(buffer), "%d:%d ", tracks[i], distance);
        prevTrack = tracks[i];
    }

    sprintf(buffer + strlen(buffer), "Total:%d\n", total);
    return strdup(buffer);
}

// Scan implementation
char* SCAN(char** argv) {
    int total = 0;
    int tracks[8];
    int currentTrack = atoi(argv[1]); // Starting track
    char buffer[1024];

    sprintf(buffer, "SCAN: Start:%d ", currentTrack);

    // Convert track numbers to integers
    for (int i = 0; i < 8; i++) {
        tracks[i] = atoi(argv[i + 2]);
    }

    // Sort tracks in ascending order
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (tracks[i] > tracks[j]) {
                int temp = tracks[i];
                tracks[i] = tracks[j];
                tracks[j] = temp;
            }
        }
    }

    // Find the first track >= currentTrack
    int startIndex = 0;
    while (startIndex < 8 && tracks[startIndex] < currentTrack) {
        startIndex++;
    }

    int prevTrack = currentTrack;

    // Move right first (higher numbered tracks)
    for (int i = startIndex; i < 8; i++) {
        int distance = abs(prevTrack - tracks[i]);
        total += distance;
        sprintf(buffer + strlen(buffer), "%d:%d ", tracks[i], distance);
        prevTrack = tracks[i];
    }

    // Jump to the **lowest track in the list**, not 0
    if (startIndex > 0) {
        int distance = abs(prevTrack - tracks[0]);
        total += distance;
        sprintf(buffer + strlen(buffer), "%d:%d ", tracks[0], distance);
        prevTrack = tracks[0];
    }

    // Continue moving right (ascending order)
    for (int i = 1; i < startIndex; i++) {
        int distance = abs(prevTrack - tracks[i]);
        total += distance;
        sprintf(buffer + strlen(buffer), "%d:%d ", tracks[i], distance);
        prevTrack = tracks[i];
    }

    sprintf(buffer + strlen(buffer), "Total:%d\n", total);
    return strdup(buffer);
}



int main(int argc, char **argv){
    //argv[1] is the starting track argv[2] - argv[9] are the tracks to be processed

    // First Come First Serve
    char* sFCFS = FCFS(argv);
    printf("%s", sFCFS);

    // Shortest Seek Time First
    char** argvCopy = copyArgv(argv, argc);
    char* sSSTF = SSTF(argvCopy, argc);
    printf("%s", sSSTF);

    // Scan
    argvCopy = copyArgv(argv, argc);
    char* scan = SCAN(argvCopy);
    printf("%s", scan);

    // C-Scan
    argvCopy = copyArgv(argv, argc);
    char* cScan = C_SCAN(argvCopy);
    printf("%s", cScan);
}