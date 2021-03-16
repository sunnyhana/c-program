#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("./04FifoW fifoname\n");
        return -1;
    }
    int fd = open(argv[1], O_RDONLY);

    char buf[256];
    int ret;
    while (1)
    {
        memset(buf, 0x00, sizeof(buf));
        ret = read(fd, buf, sizeof(buf));
        if (ret > 0)
        {
            printf("read:%s\n", buf);
        }
    }

    close(fd);
    return 0;
}
