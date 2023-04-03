#include <pthread.h>
#include <stdio.h>

#include <stdlib.h>

#define NUM_THREADS 10

int sum; /* this data is shared by the thread(s) */
void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
    pthread_t workers[NUM_THREADS]; /* the thread identifiers */
    pthread_attr_t attr; /* set of thread attributes */

    /* set the default attributes of the thread */
    pthread_attr_init(&attr);

    /* create the threads */
    for (int i =0; i < NUM_THREADS; i++)
        pthread_create(&workers[i], &attr, runner, argv[1]);

    /* wait for the thread to exit */
    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(workers[i], NULL);
    
    printf("sum = %d\n", sum);
}

/* The thread will execute in this function */
void *runner(void *param)
{
    int i, upper = atoi(param);
    sum = 0;

    if (i <= upper) {
        sum++;
        i++;
    }

    pthread_exit(0);
}