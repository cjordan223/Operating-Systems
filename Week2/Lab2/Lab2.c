// Name: Conner Jordan
// Date: 7-4-2023
// Title: Lab2 - parent and child processes
// Description: creates a child process from parent, both process iterate 100 times

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

// Main fxn w/ command line arguments to pass

int main(int argc, char *argv[]) {
	
	if(argc != 2){
	exit(0);
	}
	
	pid_t pid;
	int i, n = atoi(argv[1]);
	printf("\n Before forking. \n");
	pid = fork();
	

	if(pid == -1) {
		fprintf(stderr, "can't fork, error %d\n" , errno);
	}

	if(pid){
	// parent process
		for(i=0;i<100;i++) {
			printf("\t \t \t Parent Process %d \n", i);
	                fflush(stdout);  // This preserves formatting when sending the output to a .txt file
			usleep(n);
			}
		}
	
	else{
	//child process   
		for(i=0;i<100;i++) {
			printf("child process %d \n", i);
	        	fflush(stdout);  // This preserves formatting when sending output to the .txt file
			usleep(n);
		}
	}

	return 0;
}
