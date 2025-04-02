#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>


// usage() prints a standard usage statement
void usage(char *path) {
    fprintf(stderr, "Usage: %s -n NAME\n", path);
}

int main(int argc, char *argv[])
{
	char *name = argv[1];
	char hostName[1024];
	//gethostname(hostName, sizeof(hostName)-1);
	gethostname(hostName, sizeof(hostName));
	hostName[sizeof(hostName) - 1] = '\0';
	int pid = getpid();
	int ppid = getppid();



	if (argc != 3)
	{
		usage(argv[0]);
		exit(1);
	}
	
	// read the input parameter and exit on error
	int c;
	opterr = 0;
	while ((c = getopt(argc, argv, "n:")) != -1) 
	{
		switch (c) 
		{
			case 'n':
				name = optarg;
				break;
			default:
				usage(argv[0]);
				exit(1);
		}
	}
	
	// output on STDOUT "Welcome to Lab 1, written by USERNAME"
	printf("Welcome to Lab 1, written by %s\n", name);

	// output on STDOUT "Hostname: <hostname>"
	printf("Hostname: %s\n", hostName);

	// output on STDOUT "PID and PPID: nnnnn/nnnnn"
	printf("PID and PPID: %d/%d\n", pid, ppid);

	// output on STDOUT "Program: <pathToThisProgram>"
	printf("Program: %s\n", argv[0]);
	/*
 *  // Printing a string variable:
 char myName[32] = "Mickey Mouse";
 printf("My name is %s\n", myName);
 // Printing an integer variable:
 int myAge = 38;
 printf("My age is %i\n", myAge);
 // A string variable containing the path to the currently running program:
 argv[0]
 // C Functions you might need:
 int pid = getpid();
 int ppid = getppid();
 char hostname[1024];
 gethostname(hostname, sizeof(hostname)-1);
*/ 
	return 0;
}

