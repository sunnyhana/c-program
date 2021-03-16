#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *arg[])
{
    if (argc != 2)
    {
        printf("./04FifoW fifoname\n");
        return -1;
    }
    //当前文件有一个myfifo文件
    //打开fifo文件
    int fd = open(arg[1], O_WRONLY);
    //写文件
    char buf[256];
    int num = 1;
    while (1)
    {
        memset(buf, 0x00, sizeof(buf));
        sprintf(buf, "xiaoming%04d", num++);
        write(fd, buf, strlen(buf));
        sleep(1);
    }

    //关闭描述符
    close(fd);
    return 0;
}