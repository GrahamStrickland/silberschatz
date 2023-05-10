#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    pid = fork();
    if (pid == 0) { /* child process */
        fork();
        thread_create();
    }
    fork();

    return 0;
}