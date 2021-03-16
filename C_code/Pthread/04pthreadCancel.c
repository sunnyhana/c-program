#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thr(void *arg)
{
    while (1)
    {
        printf("I am a thread ,very happy! tid = %lu\n", pthread_self());
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, thr, NULL);

    sleep(5);
    pthread_cancel(tid); //杀死进程
    void *ret;
    pthread_join(tid, &ret);
    printf("thread exit with %d\n", (int)ret);
    return 0;
}