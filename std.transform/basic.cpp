//
// Created by elsey on 2022/2/16.
//

#include <vector>
#include <iostream>
#include <algorithm>

void write_to_cout(std::vector<int> &in) {
    for (int i = 0; i < in.size(); ++i) {
        std::cout << in[i] << ", ";
    }
}

int main() {
    std::vector<int> a = {6, 1, 9, 4, 2, 8, 10, 5, 11, 3, 7};
    std::vector<int> b = {7, 2, 3, 9, 6, 8, 1, 5, 11, 10, 4};
    std::vector<int> c;

    // Write initial states
    write_to_cout(a);
    std::cout << std::endl;
    write_to_cout(b);
    std::cout << std::endl;

    // Test algorithm
    std::transform(
            a.begin(), a.end(), b.begin(), std::back_inserter(c),
            [](int a, int b) { return a + b * b; }
    );

    write_to_cout(c);
    std::cout << std::endl;

    return 0;
}