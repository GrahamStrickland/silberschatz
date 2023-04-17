#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum = 0;
void *worker(void *param);

int main(int argc, char *argv[]) {
    pthread_t tid;

    /* create the thread */
    pthread_create(&tid, 0, worker, NULL);

    /* cancel the thread */
    pthread_cancel(tid);

    /* wait for the thread to terminate */
    pthread_join(tid, NULL);

    return 0;
}

/* The thread will execute in this function */
void *worker(void *param)
{
    int i, upper = atoi(param);
    sum = 0;

    for (i = 1; i <= upper; i++)
        sum += i;

    pthread_exit(0);
}