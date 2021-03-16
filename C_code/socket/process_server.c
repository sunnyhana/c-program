#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

//?进程回调函数
void recycle(int num)
{
    pid_t pid;
    while ((pid = waitpid(-1, NULL, WNOHANG)) > 0)
    {
        printf("child died,pid = %d\n", pid);
    }
}

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        printf("eg:./a.out port \n");
        exit(1);
    }
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

    listen(lfd, 36);
    printf("start accept>>>>>>>>>>\n");

    //! 使用信号回收子进程pcb
    struct sigaction act;
    act.sa_handler = recycle; //?    回调函数
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGCHLD, &act, NULL);

    struct sockaddr_in client_addr;
    socklen_t cli_len = sizeof(struct sockaddr_in);

    while (1)
    {
        //printf("connect-test!\n");
        int cfd;
        cfd = accept(lfd, (struct sockaddr *)&client_addr, &cli_len);
        while (-1 == cfd && errno == EINTR)
        {
            printf(" continue connecting !\n");
            cfd = accept(lfd, (struct sockaddr *)&client_addr, &cli_len);
        }
        printf("connect successful\n");
        //? 创建子进程
        pid_t pid = fork();
        char ip[64];
        if (0 == pid)
        {
            close(lfd);
            //child process
            //?通信
            while (1)
            {

                //client ip port    //?  显示客户端的IP地址和端口。
                printf("client IP:%s , port:%d ",
                       inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, ip, sizeof(ip)),
                       ntohs(client_addr.sin_port));
                char buf[1024];
                int len = read(cfd, buf, sizeof(buf));
                if (-1 == len)
                {
                    perror("read error!!!");
                    exit(1);
                }
                else if (0 == len)
                {
                    printf("客户端断开连接\n");
                    close(cfd);
                    break;
                }
                else
                {
                    printf("recv buf : %s\n", buf);
                    write(cfd, buf, len);
                }
            }
            //? 干掉子进程
            return 0;
        }
        else if (pid > 0)
        {
            //parent process
            close(cfd);
        }
    }

    close(lfd);
    return 0;
}