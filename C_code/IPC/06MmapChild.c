#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>

//mmap父子间通信

int main()
{
    //创建映射区
    int fd = open("men.txt", O_RDWR);
    int *men = mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (MAP_FAILED == men)
    {
        perror("mmap err");
    }
    //fork子进程
    pid_t pid = fork();
    if (0 == pid)
    {
        //son
        *men = 100;
        printf("CHILD: %d\n", *men);
        sleep(3);
        printf("CHILD: %d\n", *men);
    }
    else if (pid > 0)
    {
        //parent
        sleep(1);
        printf("parent:%d\n", *men);
        *men = 1001;
        printf("parent:%d\n", *men);
        wait(NULL);
    }
    munmap(men, 4);
    close(fd);
}