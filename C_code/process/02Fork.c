#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    printf("Begin....\n");
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork err!");
        exit(1);
    }
    if (pid == 0)
    {
        //
        printf("I am child, pid = %d,ppid = %d\n", getpid(), getppid());
        sleep(1);
        
    }
    else if (pid > 0)
    {
        printf("child = %d, self = %d,ppid= %d\n", pid, getpid(), getppid());
        while (1)
        {
            sleep(1);
        }
    }

    printf("END......\n");
    return 0;
}
