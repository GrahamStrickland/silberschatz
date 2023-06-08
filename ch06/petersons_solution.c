#include <stdbool.h>

int main(int argc, char* argv[])
{
    int i = 0, j = 1 - i, turn;
    bool flag[2];

    while (true) {
        flag[i] = true;
        turn = j;
        while (flag[j] && turn == j)
            ;
            /* critical section */
        flag[i] = false;
            /* remainder section */
    }

    return 0;
}