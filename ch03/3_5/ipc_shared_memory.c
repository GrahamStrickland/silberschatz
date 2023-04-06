#include <stdbool.h>

#define BUFFER_SIZE 10

void producer();
void consumer();

typedef struct {
    int x;
    int y;
} item;

item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

int main() {
    producer();
    consumer();

    return 0;
}

void producer() {
    item next_produced;

    while (true) {
        /* produce an item in next_produced */

        while (((in + 1) % BUFFER_SIZE) == out); /* do nothing */

        buffer[in] = next_produced;
        in = (in + 1) % BUFFER_SIZE;
    }
}

void consumer() {
    item next_consumed;

    while (true) {
        while (in == out); /* do nothing */

        next_consumed = buffer[out];
        out = (out + 1) % BUFFER_SIZE;

        /* consume the item in next_consumed */
    }
}