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
        printf("I am child ,pid = %d\n", pid);
        sleep(2);
    }
    else if (pid > 0)
    {
        printf("I am parent ,pid = %d\n", pid);
        int ret;

        while (0 == (ret = waitpid(pid, NULL，WNOHANG)))
        {
            sleep(1);
        }
        printf("ret = %d", ret);
        while (1)
        {
            sleep(1);
        }
    }

    return 0;
}