// Conner Jordan
// 7-11-2023
// CST 334 Lab 3 - pt 3
// implements the shell command "cat /etc/passwd | grep root" using pipes to display lines from the "/etc/passwd" file that contain the word "root".

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int fds[2];
    pipe(fds);

    if (fork() == 0)
    {
        dup2(fds[0], 0);
        close(fds[1]);
        execlp("grep", "grep", "root", NULL);
    }
    else if (fork() == 0)
    {
        dup2(fds[1], 1);
        close(fds[0]);
        execlp("cat", "cat", "/etc/passwd", NULL);
    }
    else
    {
        close(fds[0]);
        close(fds[1]);
        wait(0);
        wait(0);
    }

    return 0;
}
