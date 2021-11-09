//
// Created by Administrator on 2021/11/9.
//

#include <cstdio>
#include <omp.h>
#include <time.h>

int fib(int n) {
    int x, y;
    if (n < 2) return n;
#pragma omp task shared(x)
    x = fib(n - 1);
#pragma omp task shared(y)
    y = fib(n - 2);
#pragma omp taskwait
    return x + y;
}

int main() {
    double runtime;
    clock_t start, end;
    start = clock();
    runtime = omp_get_wtime();
    int n = 10;
    int x = fib(n);
//    sleep(2);
    runtime = omp_get_wtime() - runtime;
    end = clock();
    double elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
    printf("fib(%d) = %d, elapsed time : %f, runtime : %f", n, x, elapsed_time, runtime);
}