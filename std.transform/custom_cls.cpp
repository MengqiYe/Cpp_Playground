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

CustomCls::CustomCls(){
    x = 1;
    y = 2;
    z = 3;
}

void write_to_cout(std::vector<CustomCls> &in) {
    for (int i = 0; i < in.size(); ++i) {
        std::cout << in[i].x << ":" << in[i].y << ":" << in[i].z << ", ";
    }
}

#pragma omp declare reduction(vec_plus : std::vector<ClassCustomClsa> : \
std::transform(omp_out.begin(), omp_out.end(), omp_in.begin(), omp_out.begin(), \
[](ClassCustomClsa a, ClassCustomClsa b){ \
    ClassCustomClsa c; \
    return c; \
})) \
initializer(omp_priv = omp_orig)

int main() {
    std::vector<CustomCls> a = {CustomCls(), CustomCls(), CustomCls(), CustomCls(), CustomCls()};
    std::vector<CustomCls> b = {CustomCls(), CustomCls(), CustomCls(), CustomCls(), CustomCls()};
    std::vector<CustomCls> c;

    // Write initial states
    write_to_cout(a);
    std::cout << std::endl;
    write_to_cout(b);
    std::cout << std::endl;

    // Test algorithm
    std::transform(
            a.begin(), a.end(), b.begin(), std::back_inserter(c),
            [](CustomCls a, CustomCls b) {
                CustomCls d;
                d.x = a.x + b.y;
                d.y = a.y + b.z;
                d.z = a.z + b.x;
                return d;
            }
    );

    write_to_cout(c);
    std::cout << std::endl;

    return 0;
}
