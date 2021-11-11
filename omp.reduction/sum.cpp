//
// Created by elsey on 2021/11/11.
//

#include <stdio.h>
#include <omp.h>
#include <ctime>

#define t unsigned long long

int sum(long N) {
    long i;
    t ret = 0;
//    omp_set_num_threads(4);
#pragma omp parallel
    {
        t sum_th = 0;
#pragma omp for // reduction(+:sum)
        for (i = 0; i <= N; ++i) sum_th = sum_th + i;
#pragma omp atomic
        ret += sum_th;
    };
    printf("Sum = %d\n", ret);
    return ret;
}

int main() {
    double runtime;
    clock_t start, end;
    start = clock();
    runtime = omp_get_wtime();
    int N = 100000;
    t ret = sum(N);
    runtime = omp_get_wtime() - runtime;
    end = clock();
    double elapsed_time = (end - start) / (double) CLOCKS_PER_SEC;
    printf("sum(%ld) = %llu\n", N, ret);
    printf("Elapsed time : %f, runtime : %f\n", elapsed_time, runtime);
    return 0;
}