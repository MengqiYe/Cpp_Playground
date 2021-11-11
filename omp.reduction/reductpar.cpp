//
// Created by elsey on 2021/11/11.
//
// reductpar.c

#include <omp.h>
#include <cstdlib>

#define INT_MIN 10

int main(){
    int m = INT_MIN;
    int *ndata = (int *)calloc(sizeof (int *), 4);

#pragma omp parallel reduction(max:m) num_threads(ndata)
    {
        int t = omp_get_thread_num();
        int d = ndata[t];
        m = d > m ? d : m;
    };

    return 0;
}

