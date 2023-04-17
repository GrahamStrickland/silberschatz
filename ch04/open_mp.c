#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int N = 10, i;
    int a[] = { 1, 2, 4, 3, 5, 10, 92, 41, 2, 11 },
        b[] = { 28, 1, 45, 76, 12, 11, 86, 3, 41, 14 },
        c[N];

    /* sequential code */

    #pragma omp parallel
    {
        printf("I am a parallel region.\n");
    }

    /* sequential code */

    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    for (i = 0; i < N; i++)
        printf(i != N - 1 ? "c[%d] = %d, ": "c[%d] = %d\n", i, c[i]);

    return 0;
}