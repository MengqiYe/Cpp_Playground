//
// Created by elsey on 2021/9/25.
//
#include <omp.h>
#include <cstdio>

int main()
{
    int i = 0, N = 10;
#pragma omp parallel
#pragma omp for
    for (i=0; i<N; i++) {
        printf("For : %d / %d\n", i, N);
    }
    return 0;
}
