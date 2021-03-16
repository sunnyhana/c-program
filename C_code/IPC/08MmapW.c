#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
typedef struct student
{
    int sid;
    char sname[20];
} Student;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("./a.out filename\n") return -1;
    }
    //1 open file
    int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0666);
    int length = sizeof(Student);
    ftruncate(fd, length);
    //mmap
    Student *stu = mmap(NULl, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (MAP_FAILED)
    {
        perror("mmap err");
        return -1;
    }
    int num = 1;

    //修改内存数据
    while (1)
    {
        stu->sid = num;
        sprintf(stu->sname, "xiaoming_%o3d", num++);
        sleep(1); //隔一秒修改一次映射区内容；
    }
    //释放映射区和文件描述符
    munmap(stu, length);
    close(fd);
    return 0;
}