#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main()
{
    struct itimerval myit = {{0, 0}, {3, 0}}; //定义三秒后发送SIGALRM信号
    setitimer(ITIMER_REAL, &myit, NULL);
    while (1)
    {
        printf("who can kill me!\n");
        sleep(1);
    }
    return 0;
}