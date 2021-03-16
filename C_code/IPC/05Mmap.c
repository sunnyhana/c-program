#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd = open("men.txt", O_RDWR);

    char *men = mmap(NULL, 8, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (MAP_FAILED == men)
    {
        perror("mmap err");
        return -1;
    }
    strcpy(men, "hello!");

    //释放
    munmap(men, 8);
    close(fd);
    return 0;
}