#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

#include <arpa/inet.h>
#include <ctype.h>

#define SERV_PORT 6666
#define SERV_IP "127.0.0.1"

int main()
{
    int lfd, cfd;
    struct sockaddr_in serv_addr, clie_addr;
    socklen_t clie_addr_len;
    char buf[BUFSIZ];
    int n; //记录实际接收多少个数据

    lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == lfd)
    {
        printf("lfd返回值出错");
        return 0;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    listen(lfd, 128);

    clie_addr_len = sizeof(clie_addr);
    cfd = accept(lfd, (struct sockaddr *)&clie_addr, &clie_addr_len);

    //? while写在accept后面：服务端与客户端建立一次后循环接收数据
    //? while写在accept前面：服务端循环与客户端建立连接再接收数据，

    while (1)
    {
        n = read(cfd, buf, sizeof(buf));

        for (int i = 0; i < n; i++)
            buf[i] = toupper(buf[i]);
        write(cfd, buf, n);
    }

    close(cfd);
    close(lfd);

    return 0;
}