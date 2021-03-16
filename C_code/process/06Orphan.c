#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//孤儿进程

int main()
{
    pid_t pid = 0;
    pid = fork();
    if (0 == pid)
    {
        while (1)
        {
            printf("I am child, pid = %d, ppid = %d \n", getpid(), getppid());
            sleep(1);
        }
    }
    else if (pid > 0)
    { //father
        printf("I am father , pid = %d,ppid = %d\n", getpid(), getppid());
        sleep(3);
        printf("I am father ,will out, pid = %d,ppid = %d\n", getpid(), getppid());
    }
}