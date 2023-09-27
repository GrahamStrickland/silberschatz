#include <pthread.h>

int main(int argc, char *argv[]) {
    pthread_mutex_t mutex;

    /* create and initialise the mutex lock */
    pthread_mutex_init(&mutex, NULL);

    /* acquire the mutex lock */
    pthread_mutex_lock(&mutex);

    /* critical section */

    /* release the mutex lock */
    pthread_mutex_unlock(&mutex);

    return 0;
}

