#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//控制子进程

int main()
{
    int n = 5;
    int i = 0;
    pid_t pid = 0;
    for (i; i < n; i++)
    {
        pid = fork();
        if (0 == pid)
        { //son
            printf("I am child%d, pid = %d, ppid = %d \n", i, getpid(), getppid());
            break; //子进程退出循环的接口
        }
        else if (pid > 0)
        { //father
            printf("I am father%d , pid = %d,ppid = %d\n", i, getpid(), getppid());
        }
    }
    sleep(i);
    if (i < 5)
    {
        printf("I am child,will exit, pid = %d, ppid = %d \n", getpid(), getppid());
    }
    else
    {
        printf("I am father , will out ,pid = %d,ppid = %d\n", getpid(), getppid());
    }

    return 0;
}
