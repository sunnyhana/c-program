#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        printf("eg: .a.out port\n");
        exit(1);
    }
    struct sockaddr_in serv_addr;
    socklen_t serv_len = sizeof(serv_addr);
    int port = atoi(argv[1]);

    //!创建套接字
    int lfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&serv_addr, 0, serv_len);               //! 初始化服务器 sockaddr_in;
    serv_addr.sin_family = AF_INET;                //! 地址簇
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //! 监听本机所有的IP
    serv_addr.sin_port = htons(port);              //! 设置端口

    //绑定IP和端口
    bind(lfd, (struct sockaddr *)&serv_addr, serv_len);

    //设置同时最大监听个数
    listen(lfd, 36);
    printf("start accept>>>>>>>>>>>>>>>>\n");

    struct sockaddr_in client_addr;
    socklen_t cli_len = sizeof(client_addr);

    //最大文件描述符
    int maxfd = lfd;
    //文件描述符集合
    fd_set reads, temp;

    FD_ZERO(&reads); //! 初始化读集合
    FD_SET(lfd, &reads);
    while (1)
    {
        //?委托内核做IO检测
        temp = reads;
        int ret = select(maxfd + 1, &temp, NULL, NULL, NULL);
        if (-1 == ret)
        {
            perror("select error!!!!!!");
            exit(1);
        }

        //客户端发起新连接
        if (FD_ISSET(lfd, &temp))
        {
            //接受连接请求。
            int cfd = accept(lfd, (struct sockaddr *)&client_addr, &cli_len);
            if (-1 == cfd)
            {
                perror("accept error!!!!!!");
                exit(1);
            }
            //!打印连接成功的IP和端口号
            char ip[64];
            printf("new client IP:%s , Port:%d\n",
                   inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, ip, sizeof(ip)),
                   ntohs(client_addr.sin_port));

            //? 将cfd加入到待检测的读集合中，-下一次就可以检测到。
            FD_SET(cfd, &reads);
            //! 更新最大文件描述符
            maxfd = maxfd < cfd ? cfd : maxfd;
        }

        //已经连接到客户端有数据到达。
        for (int i = lfd + 1; i <= maxfd; ++i)
        {
            if (FD_ISSET(i, &temp))
            {
                char buf[1024] = {0};
                int len = recv(i, buf, sizeof(buf), 0);
                if (-1 == len)
                {
                    perror("recv error!!!!!!!!");
                    exit(1);
                }
                else if (0 == len)
                {
                    printf("客户端已经断开了链接呢");
                    close(i);
                    //从读集合中删除
                    FD_CLR(i, &reads);
                }
                else
                {
                    printf("recv buf : %s", buf);
                    send(i, buf, strlen(buf) + 1, 0); //?   +1 防止buf没有初始化，发出的字符串没'\0'。
                }
            }
        }
    }

    close(lfd);
    return 0;
}
