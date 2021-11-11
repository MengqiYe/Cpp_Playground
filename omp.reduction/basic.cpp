//
// Created by elsey on 2021/11/11.
//
#include <omp.h>
#include <cstdio>

int f(int x) { return x + 1; }
int g(int x) { return x + 2; }
int h(int x) { return x + 3; }

int f(int x, int i) { return x + i; }


int sol1() {
    double result = 0;
    int x = 5;
#pragma omp parallel
    {
        double local_result;
        int num = omp_get_thread_num();
        if (num == 0) local_result = f(x);
        else if (num == 1) local_result = g(x);
        else if (num == 2) local_result = h(x);
#pragma omp critical
        result += local_result;

        return result;
    }
}

int sol2(){
    double result = 0;
#pragma omp parallel
    {
        int i;
        int N = 10;
        int x = 5;
        double local_result;
#pragma omp for
        for (i=0; i<N; i++) {
            local_result = f(x,i);
#pragma omp critical
            result += local_result;
        } // end of for loop
    }
    return result;
}

int main()
{
    int results = sol2();
    printf("results : %d", results);
    return 0;
}