//
// Created by elsey on 2021/11/11.
//

#include <algorithm>
#include <ctime>
#include <omp.h>
#include <stdio.h>
#include <vector>

#include <iostream>

#pragma omp declare reduction(vec_double_plus : std::vector<double> : \
std::transform(omp_out.begin(), omp_out.end(), omp_in.begin(), omp_out.begin(), std::plus<double>())) \
initializer(omp_priv = omp_orig)

void solution(std::vector<float> &res, int m) {

    omp_set_num_threads(4);
    int size = 10;
    std::vector<double> w(size,0);

#pragma omp parallel for reduction(vec_double_plus:w)
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < w.size(); ++j)
            w[j] += 1;

#pragma omp barrier
    for(auto i:w)
    {
//        printf("i : %d\n", i);
        if (i != 4) {
            std::cout << i << std::endl;
        }
    }


}

int main() {
    double runtime;
    clock_t start, end;
    start = clock();
    runtime = omp_get_wtime();
    int n = 10;
    std::vector<float> res(n, 0);
    solution(res, n);
    runtime = omp_get_wtime() - runtime;
    end = clock();
    double elapsed_time = (end - start) / (double) CLOCKS_PER_SEC;
//    printf("Elapsed time : %f, runtime : %f", elapsed_time, runtime);
    return 0;
}
