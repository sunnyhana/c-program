#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>

#define _FILE_NAME_FORMAT_ "%s/log/mydaemon.%ld" //定义文件名格式化

void touchfile(int num)
{
    char *HomeDir = getenv("HOME");
    char strFilename[256] = {0};
    sprintf(strFilename, _FILE_NAME_FORMAT_, HomeDir, time(NULL));

    int fd = open(strFilename, O_RDWR | O_CREAT, 0666);
    if (fd < 0)
    {
        perror("open err");
        exit(1);
    }
}

int main()
{
    //创建子进程
    pid_t pid = fork();
    if (pid > 0)
    {
        exit(1);
    }

    //当会长（设置会话）
    setsid();
    //设置权限掩码
    umask(0);
    //切换目录
    chdir(getenv("HOME"));
    //关闭文件描述符
    //close(1),close(0),close(2);
    //执行核心逻辑
    struct itimerval myit = {{60, 0}, {60, 0}};
    setitimer(ITIMER_REAL, &myit, NULL);
    struct sigaction act;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    act.sa_handler = touchfile;

    sigaction(SIGALRM, &act, NULL);

    while (1)
    {
        //每隔一分钟在/home/itheima/log下创建文件
        sleep(1);
        // do sth
    }

    //退出
    return 0;
}