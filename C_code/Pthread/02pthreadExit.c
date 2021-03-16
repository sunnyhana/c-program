#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thr(void *arg)
{
    printf("I am a thread, pid = %d, tid = %lu\n", getpid(), pthread_self());

    return NULL;
}
int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, thr, NULL);
    printf("I am main thread, pid = %d, tid = %lu\n", getpid(), pthread_self());
    pthread_exit(NULL);

    return 0;
}