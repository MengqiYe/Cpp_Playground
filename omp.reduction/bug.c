//
// Created by elsey on 2021/11/12.
//

#include <stdio.h>

void my_sum_fun(int* outp, int* inp) {
    printf("%d @ %p += %d @ %p\n", *outp, outp, *inp, inp);
    *outp = *outp + *inp;
}

int my_init(int* orig) {
    printf("orig: %d @ %p\n", *orig, orig);
    return *orig;
}

#pragma omp declare reduction(my_sum : int : my_sum_fun(&omp_out, &omp_in) initializer(omp_priv = my_init(&omp_orig))

int main()
{
    int s = 0;
#pragma omp parallel for reduction(my_sum : s)
    for (int i = 0; i < 2; i++)
        s+= 1;

    printf("sum: %d\n", s);
}