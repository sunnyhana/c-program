#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int n = 5;
    int i;
    pid_t pid;
    for (i = 0; i < n; i++)
    {
        pid = fork();
        if (0 == pid)
        {
            break;
        }
    }
    if (5 == i)
    {
        //parent
        printf("I am parent!\n");
        while (1)
        {
            pid_t wpid = waitpid(-1, NULL, WNOHANG);
            if (-1 == wpid)
            {
                break;
            }
            else if (wpid > 0)
            {
                printf("waitpid wpid = %d\n", wpid);
            }
        }
        while (1)
        {
            sleep(1);
        }
    }
    if (i < 5)
    {
        sleep(i);
        printf("I am child , i = %d; pid = %d\n", i, getpid());
    }
}
