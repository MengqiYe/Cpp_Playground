//
// Created by elsey on 2021/11/11.
//
#include <omp.h>
#include <ctime>
#include <cstdio>

#define N 10

void solution()
{
    int i;
    int a = 0;
#pragma omp parallel
#pragma omp for default(none) lastprivate(a)
    for (i = 0; i < N; ++i) {
        a += i;
        printf("i : %d, a : %d\n", i, a);
    }
#pragma omp barrier
    printf("a : %d\n", a);
}


int main() {
    double runtime;
    clock_t start, end;
    start = clock();
    runtime = omp_get_wtime();
    solution();
    runtime = omp_get_wtime() - runtime;
    end = clock();
    double elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
    printf("Elapsed time : %f, runtime : %f", elapsed_time, runtime);
}
