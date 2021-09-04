//
// Created by elsey on 2021/9/4.
//

#include <vector>
#include <iostream>
#include "print.h"

int main() {

    std::vector<int> vec1 = {0, 1, 2};
    std::vector<int> vec2 = {3, 4, 5};
    std::cout << vec1 << std::endl;
    std::cout << vec2 << std::endl;

    copy(vec2.cbegin(), vec2.cend(), std::back_inserter(vec1));

    std::cout << vec1 << std::endl;
    std::cout << vec2 << std::endl;

    return 0;
}