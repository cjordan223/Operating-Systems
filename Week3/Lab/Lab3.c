// Conner Jordan
// 7-11-2023
// CST 334 - Lab3 pt 1
// demonstrates inter-process communication using pipes by executing the "ls" command and passing its output to the "more" command.

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int fds[2];
    pipe(fds);
    /*child 1 duplicates downstream into stdin */
    if (fork() == 0)
    {
        dup2(fds[0], 0);
        close(fds[1]);
        execlp("more", "more", 0);
    }
    /*child 2 duplicates upstream into stdout */
    else if (fork() == 0)
    {
        dup2(fds[1], 1);
        close(fds[0]);
        execlp("ls", "ls", 0);
    }
    else
    { /*parent closes both ends and wait for children*/
        close(fds[0]);
        close(fds[1]);
        wait(0);
        wait(0);
    }
    return 0;
}