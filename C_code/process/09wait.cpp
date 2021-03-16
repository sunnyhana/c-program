#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();
    if (0 == pid)
    {
        std::cout << "I am child ,will die" << std::endl;
        sleep(2);
        //return 101;
        exit(102);
    }
    else if (pid > 0)
    {
        std::cout << "I am parent ,will for child die?" << std::endl;
        int statut;

        pid_t wpid = wait(&statut);
        std::cout << "wait ok,wpid =" << wpid << "pid = " << pid << std::endl;

        if (WIFEXITED(statut))
        {
            std::cout << "child exit with " << WIFEXITED(statut) << std::endl;
        }
        if (WIFSIGNALED(statut))
        {
            std::cout << "child killed by " << WTERMSIG(statut);
        }

        while (1)
        {
            sleep(1);
        }
    }
}