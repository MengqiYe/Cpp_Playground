//
// Created by elsey on 2021/11/11.
//

#include <ctime>
#include <omp.h>
#include <cstdio>

#define t unsigned long long

class CustomCLS{
public:
    CustomCLS();
    int value;

    CustomCLS operator+(CustomCLS&rhs);
    CustomCLS operator+(int&rhs);
};

CustomCLS::CustomCLS() {
    value = 0;
}

CustomCLS CustomCLS::operator+(CustomCLS &rhs) {
    this->value = this->value + rhs.value;
    return *this;
}

CustomCLS CustomCLS::operator+(int &rhs) {
    this->value = this->value + rhs;
    return *this;
}

CustomCLS solution(long N) {
    int i;
    CustomCLS sum;
//    omp_set_num_threads(4);
#pragma omp parallel
    {
#pragma omp for reduction(+:sum)
        for (i = 0; i <= N; ++i) sum + i;
    };
    printf("Sum = %d\n", sum);
    return sum;
}

int main() {
    double runtime;
    clock_t start, end;
    start = clock();
    runtime = omp_get_wtime();
    int N = 10000;
    CustomCLS ret = solution(N);
    runtime = omp_get_wtime() - runtime;
    end = clock();
    double elapsed_time = (end - start) / (double) CLOCKS_PER_SEC;
    printf("solution(%ld) = %d, elapsed time : %f, runtime : %f", N, ret.value, elapsed_time, runtime);
    return 0;
}

