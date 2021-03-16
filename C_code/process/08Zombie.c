#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//僵尸进程

int main()
{
    pid_t pid = 0;
    pid = fork();
    if (0 == pid)
    { //child
        printf("I am child, pid = %d, ppid = %d \n", getpid(), getppid());
        sleep(2);
        printf("I am child, will die ！pid = %d, ppid = %d \n", getpid(), getppid());
    }
    else if (pid > 0)
    { //father
        while (1)
        {
            printf("I am father ,very happy! pid = %d,ppid = %d\n", getpid(), getppid());
            sleep(1);
        }
    }
}
