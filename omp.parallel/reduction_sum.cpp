//
// Created by elsey on 2021/11/10.
//
#include <omp.h>
#include <cstdio>
#include <ctime>

static long num_steps = 100000;
double step;
#define NUM_THREADS 2

void main_omp()
{
    int i;
    double x, pi, sum = 0.0;
    step = 1.0 / (double)num_steps;
    omp_set_num_threads(NUM_THREADS);
#pragma omp parallel for private (x) reduction (+:sum)
    for(i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    pi = sum * step;
    printf("pi : %f\n", pi);
}

void main_loop()
{
    int i;
#pragma omp parallel for
    for(i = 0; i < num_steps; i++);
}

int main(){
    double runtime;

    clock_t start, end;
    start = clock();
    runtime = omp_get_wtime();
//    main_loop();
    main_omp();
    runtime = omp_get_wtime() - runtime;
    end = clock();

    double elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
    printf("Elapsed time : %f, runtime : %f\n", elapsed_time, runtime);

    return 0;
}