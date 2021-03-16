#include <stdio.h>
#include <unistd.h>

int main()
{
    //int execlp(const char *file, const char *arg, .../* (char  *) NULL */);
    // execlp("ls", "ls", "-l", "--color=auto", NULL);
    //不需要判断返回值
    // perror("exec err");

    execl("/bin/ls", "ls", "-l", "--color=auto", NULL);
    //不需要判断返回值
    perror("exec err");

    return 0;
}
