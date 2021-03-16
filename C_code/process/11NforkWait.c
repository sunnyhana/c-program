#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int n = 5;
    int i = 0;
    pid_t pid;
    for (i = 0; i < n; i++)
    {
        pid = fork();
        if (0 == pid)
        {
            printf("I am child  pid = %d\n", getpid());
            break;
        }
    }
    sleep(i);
    //i=5 父进程会将上面循环走完的
    if (i == 5)
    {
        for (i = 0; i < 5; i++)
        {
            pid_t wpid = wait(NULL);
            printf("wpid = %d\n", wpid);
        }
        while (1)
        {
            /* code */
            sleep(1);
        }
    }
}