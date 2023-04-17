#include <cmath>
#include <ctime>
#include <iostream>

#include <tbb/tbb.h>

void apply(float value);

int main(int argc, char* argv[]) {
    int n = 100;
    float v[n];

    std::srand(time(0));
    
    for (int i = 0; i < n; i++) {
        v[i] = random();
    }

    parallel_for(size_t(0), n, [=](size_t i) {apply(v[i]);});

    return 0;
}

void apply(float value) {
    std::cout << std::ios::scientific << value << std::endl;
}