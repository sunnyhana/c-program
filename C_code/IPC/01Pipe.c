#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if (0 == pid)
    {
        //son
        sleep(3);
        write(fd[1], "zhangwen", 8);
    }
    else if (pid > 0)
    {
        //parent
        char buf[12] = {0};
        int ret = read(fd[0], buf, sizeof(buf));
        if (ret > 0)
        {
            write(STDOUT_FILENO, buf, ret);
        }
    }
    return 0;
}