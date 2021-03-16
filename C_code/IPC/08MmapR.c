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
int main(int argc, chat *argv[])
{
    //open file
    int fd = open(argv[1], O_RDWR);

    //mmap
    int length = sizeof(Student);
    Student *stu = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (MAP_FAILED == stu)
    {
        perror("mmap err");
        return -1;
    }
    //read date
    while (1)
    {
        printf("sid = %d,sname =%d\n", stu->sid, stu->sname);
        sleep(1);
    }

    //close and munmap
    munmap(stu, length);
    close(fd);
    return 0;
}