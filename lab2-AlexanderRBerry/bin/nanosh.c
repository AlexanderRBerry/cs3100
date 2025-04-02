/* 
 CS 3100 Lab 2 - by Alexander Berry
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void cmdExit(int argc, char **argv) {
	if(argc != 1){
		errno = EINVAL;
		perror("Invalid number of arguments");
		return;
	}
	exit(0);
}

// getParameters returns the argc, the number of words found in cmd
//  while populating argv with pointers to each word
// spaces, tabs, and newlines are removed
int getParameters(char *cmd, char **argv) {
	char *token;
	int argc = 0;
	token = strtok(cmd, " \t\n");
	while (token != NULL) {
		argv[argc] = token;
		argc++;
		token = strtok(NULL, " \t\n");
	}
	argv[argc] = NULL;		// set last + 1 argument to NULL
	return argc;
}
//Prints current directory
//Use getcwd instead of enviromental variable "PWD"
//"PWD" does not update on its own
void PrintDirectory(int myArgc){
	if(myArgc != 1){
	errno = EINVAL;
	perror("Invalid number of arguments");
	return;
	}
	char workingDirectory[1024];
	if(getcwd(workingDirectory, sizeof(workingDirectory)) != NULL){
		printf("%s\n", workingDirectory);
	}
	else{
		perror("Error printing directory");
	}
}

//Change current directory
void ChangeDirectory(int myArgc, char **myArgv){
	if(myArgc > 2){
		errno = EINVAL;
		perror("Invalid number of arguments");
		return;
	}
	const char *myDir = myArgv[1];
	if(chdir(myDir) == -1){
		perror("Directory not found\n");
		return;
	}

}
//Change directory to the $HOME enviromental variable
void ChangeToHomeDirectory(){
	char *homeDirectory = getenv("HOME");
	if(homeDirectory == NULL){
		perror("Error: HOME environment variable may not be set.\n");
		return;
	}
	if(chdir(homeDirectory) == -1){
		perror("Failed to change directory\n");
	}
}
//Attempt to execute an unhandled command 
void UnknownCommand(int myArgc, char **myArgv){
	int rv = fork();

	// This is the child
	if(rv == 0){
		execvp(myArgv[0], myArgv);
		perror("Failed to execute command");
		exit(1);
	}
	// This is the parent
	else if(rv > 0){
		int childExitStatus;
		waitpid(rv, &childExitStatus, 0);
	}
	else{
		perror("Failed to fork");
	}
}
int main(int argc, char **argv) {

	char cmd[1024]; // Array to store command
	char *rc; // Return value of fgets (NULL = failure)
	int myArgc = 0; //Argument count
	char *myArgv[1000]; //Array to store arguments

	while (1) {
		printf("nanosh: ");
		fflush(stdout);
		rc = fgets(cmd, sizeof(cmd), stdin);
		if (rc == NULL) {
			exit(0);
		}
		myArgc = getParameters(cmd, myArgv);

		// if no words typed: restart loop
		if (myArgc == 0) {			
			continue;
		}

		// if the first word is "exit", terminate the program
		if (strcmp(myArgv[0], "exit") == 0) {
			cmdExit(myArgc, myArgv);
			continue;
		}
		// if the first word is "pwd", print the working directory
		if(strcmp(myArgv[0], "pwd") == 0){
			PrintDirectory(myArgc);
			continue;
		}
		// if the first word is "cd" change the directory
		// if cd is the only word change to the home directory
		// otherwise change to directory to the path provided
		if(strcmp(myArgv[0], "cd") == 0){
			if(myArgc == 1){
				ChangeToHomeDirectory();
				continue;
			}
			else{
			ChangeDirectory(myArgc, myArgv);
			continue;
			}
		}
		UnknownCommand(myArgc, myArgv);
	}
	return 0;
} 
