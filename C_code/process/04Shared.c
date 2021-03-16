#include <stdio.h>
#include <unistd.h>

//父子进程不共享全局变量

int var = 100;
int main()
{
    pid_t pid = fork();
    if (0 == pid)
    {
        printf("var = %d, child ,pid = %d,ppid = %d;\n", var, getpid(), getppid()); //打印var= 100
        var = 1001;
        printf("var = %d, child第二次说话 ,pid = %d,ppid = %d;\n", var, getpid(), getppid()); //打印var= 1001
        sleep(3);
        printf("var = %d, child第三次说话 ,pid = %d,ppid = %d;\n", var, getpid(), getppid()); //打印var= 1001
    }
    else if (0 < pid)
    {
        sleep(1);                                                                    //保证子进程能够修改var的值成功
        printf("var = %d, parent ,pid = %d,ppid = %d;\n", var, getpid(), getppid()); //打印var= 100
        var = 501;
        printf("var = %d, parent第二次说话 ,pid = %d,ppid = %d;\n", var, getpid(), getppid()); //打印var= 501
        sleep(3);
    }
    return 0;
}