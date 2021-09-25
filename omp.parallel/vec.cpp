//
// Created by elsey on 2021/9/25.
//
#include <cstdio>
#include <vector>

int main() {
    std::vector<int> s{0, 1, 2, 3, 4, 5, 6};

#pragma omp parallel
    for (std::vector<int>::const_iterator i = s.begin(); i != s.end(); ++i) {
#pragma omp single nowait
        printf("%d\n", *i);
    }

    return 0;
}
