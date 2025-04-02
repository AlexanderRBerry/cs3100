// dininglib.h - contains structures needed by the Dining Philosphers program

int dpInitialize(int,int);
int dpAddPhilosopher(int);
int dpCommence();
int dpReserveChopstick(int);
int dpReleaseChopstick(int);
int dpShortWait();
int dpDine();
int dpThink();
int dpTerminate();

enum State {WAITING, DINING, THINKING};

struct Table {
	int isValid;		// true if entry is valid
	int number;			// the number of this entry
	pthread_t pthread;	// the pthread_t of this philosopher
	int leftAcquired;	// true if the left chopstick is held
	int rightAcquired;	// true if the right chopstick is held
	int needToWait;		// true if a chopstick is busy
	int timeSpentDining;	// time in seconds spent Dining
	int timeSpentThinking;	// time in seconds spent thinking
	int timeSpentWaiting;	// time in seconds spent waiting for a chopstick
	enum State state;	// DINING, WAITING, THINKING
};
