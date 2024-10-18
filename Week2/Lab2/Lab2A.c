// Name: Conner Jordan
// Date: 7-4-2023
// Title: Lab2A - parent and child processes, exec() and wait() processes
// Description: Child process completes, parent process waits for child process to complete before continuing it's execution`

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    printf("Before forking.\n");
    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Can't fork, error %d\n", errno);
    }

    if (pid == 0) {
        execlp("/bin/ls", "ls", NULL);
    } else {
        wait(NULL);
        printf("Child Complete\n");
    }

    return 0;
}

