//
// Created by elsey on 2022/2/16.
//

#include <vector>
#include <iostream>
#include <algorithm>

class Dat {
public:
    Dat();
    int x;
    int y;
    int z;
};

Dat::Dat(){
    x = 1;
    y = 2;
    z = 3;
}


void write_to_cout(std::vector<Dat> &in) {
    for (int i = 0; i < in.size(); ++i) {
        std::cout << in[i].x << ":" << in[i].y << ":" << in[i].z << ", ";
    }
}

int main() {
    std::vector<Dat> a = {Dat(), Dat(), Dat(), Dat(), Dat()};
    std::vector<Dat> b = {Dat(), Dat(), Dat(), Dat(), Dat()};
    std::vector<Dat> c;

    // Write initial states
    write_to_cout(a);
    std::cout << std::endl;
    write_to_cout(b);
    std::cout << std::endl;

    // Test algorithm
    std::transform(
            a.begin(), a.end(), b.begin(), std::back_inserter(c),
            [](Dat a, Dat b) { return Dat(); }
    );

    write_to_cout(c);
    std::cout << std::endl;

    return 0;
}
