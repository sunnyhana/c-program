#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if (0 == pid)
    {
        printf("I am child ,will die\n");
        sleep(2);
    }
    else if (pid > 0)
    {
        printf("I am parent ,wait for child die!\n");
        int status;

        pid_t wpid = wait(&status);
        printf("wait ok! wpid = %d,pid = %d\n", wpid, pid);
    }
    // if (WIFEXITED(status))
    // {
    //     printf("child exit with %d\n ", WIFEXITED(status));
    // }
    // if (WIFSIGNALED(status))
    // {
    //     printf("child killed by %d\n", WTERMSIG(status));
    // }
    if (WIFEXITED(status))
    {
        printf("child exit with %d\n ", WIFEXITED(status));
    }

    // while (1)
    // {
    //     sleep(1);
    // }
}