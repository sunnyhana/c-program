#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <pthread.h>
#include <errno.h>

typedef struct SockInfo
{
    int fd;                  //
    struct sockaddr_in addr; //存放IP地址的结构体
    pthread_t id;            //线程ID

} SockInfo;

//子线程处理函数
void *worker(void *arg)
{
    char ip[64];
    char buf[1024];
    SockInfo *info = (SockInfo *)arg;
    //通信
    while (1)
    {
        printf("Client IP:%s, port :%d\n", inet_ntop(AF_INET, &info->addr.sin_addr.s_addr, ip, sizeof(ip)), ntohs(info->addr.sin_port));
        int len = read(info->fd, buf, sizeof(buf));
        if (-1 == len)
        {
            perror("read error!!!!");
            //exit(1);  会连主线程一起退出
            pthread_exit(NULL);
        }
        else if (0 == len)
        {
            printf("客户端已经断开了连接\n");
            close(info->fd);
            break;
        }
        else
        {
            printf("recv buf : %s\n", buf);
            write(info->fd, buf, len);
        }
    }
    return NULL;
}

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        printf("eg: ./a.out port \n");
        exit(1);
    }
    int i = 0;
    struct sockaddr_in serv_addr;
    socklen_t serv_len = sizeof(serv_addr);
    int port = atoi(argv[1]);
    int lfd = socket(AF_INET, SOCK_STREAM, 0);

    //? 初始化服务器，
    memset(&serv_addr, 0, serv_len);
    serv_addr.sin_family = AF_INET;                //地址簇
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //监听本机所有IP
    serv_addr.sin_port = htons(port);              //设置端口
    //? 绑定IP和端口
    bind(lfd, (struct sockaddr *)&serv_addr, serv_len);

    //设置最大监听数；
    listen(lfd, 36);
    printf("start accept>>>>>>>>>>\n");

    SockInfo info[256];
    //规定info中fd == -1；
    socklen_t cli_len = sizeof(struct sockaddr_in);
    for (i = 0; i < sizeof(info) / sizeof(info[0]); i++)
    {
        info[i].fd = -1;
    }

    while (1)
    {
        //选一个没有被使用的，最小的数组元素；
        for (i = 0; i < sizeof(info) / sizeof(info[0]); i++)
        {
            if (info[i].fd == -1)
            {
                break;
            }
            if (256 == i)
            {
                break;
            }
        }
        //主线程- 等待接受连接请求
        info[i].fd = accept(lfd, (struct sockaddr *)&info[i].addr, &cli_len);
        //创建子线程 - 通信
        pthread_create(&info[i].id, NULL, worker, &info[i]); //worker 子线程回调函数。
        //设置线程分离
        pthread_detach(info[i].id);
        i++;
        if (256 == i)
        {
            break;
        }
    }
    close(lfd);

    //只退出主线程
    pthread_exit(NULL);
    return 0;
}