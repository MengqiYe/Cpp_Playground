//
// Created by elsey on 2022/2/16.
//

#include <vector>
#include <iostream>
#include <algorithm>

class CustomCls {
public:
    CustomCls();

    int x;
    int y;
    int z;
};

CustomCls::CustomCls() {
    x = 0;
    y = 0;
    z = 0;
}

void write_to_cout(std::vector<CustomCls> &in) {
    for (int i = 0; i < in.size(); ++i) {
        std::cout << in[i].x << ":" << in[i].y << ":" << in[i].z << ", ";
    }
}

//#pragma omp declare reduction(vec_plus : std::vector<CustomCls> : \
//std::transform(omp_out.begin(), omp_out.end(), omp_in.begin(), omp_out.begin(), \
//[](ClassData a, ClassData b){ \
//    ClassData c; \
//    c.x = a.x + b.x; \
//    c.y = a.y + b.y; \
//    c.z = a.z + b.z; \
//    return c; \
// })) \
//initializer(omp_priv = omp_orig)

int main() {
    std::vector<CustomCls> vec = {CustomCls(), CustomCls(), CustomCls(), CustomCls(), CustomCls()};

#pragma omp parallel default(none) shared(vec)
#pragma omp for schedule(dynamic, 1) reduction(+:vec)
    for (int i = 0; i < 102; ++i) {
        vec[i % 5].x += 1;
    }

    write_to_cout(vec);
    std::cout << std::endl;

    return 0;
}
