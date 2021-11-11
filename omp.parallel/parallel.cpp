//
// Created by elsey on 2021/9/25.
//
#include <omp.h>
#include <cstdio>

int main() {
    int i;
    int N = 18;
#pragma omp parallel
    {
        int threadnum = omp_get_thread_num(), numthreads = omp_get_num_threads();
        int low = N * threadnum / numthreads, high = N * (threadnum + 1) / numthreads;

        printf("threadnum : %d, numthreads : %d, low : %d, high : %d\n", threadnum, numthreads, low, high);

        for (i = low; i < high; i++);
        // do something with i
    }

    return 0;
}
