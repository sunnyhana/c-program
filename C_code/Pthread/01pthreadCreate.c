#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thr(void *arg)
{
    printf("I am a thread ! pid = %d\n", getpid());
    return NULL;
}
int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, thr, NULL);
    printf("I am a main thread,pid = %d\n", getpid());
    sleep(1);
    return 0;
}