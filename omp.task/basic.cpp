//
// Created by Administrator on 2021/11/11.
//
#include <omp.h>

void foo ();
void bar (){
    return ;
}

int main() {
#pragma omp parallel
    {
#pragma omp task
        foo();
#pragma omp barrier
#pragma omp single
        {
#pragma omp task
            bar();
        }
    }
    return 0;
}