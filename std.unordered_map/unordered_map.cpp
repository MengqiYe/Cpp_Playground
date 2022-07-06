//
// Created by elsey on 2022/3/4.
//

#include <unordered_map>
#include <iostream>

int main()
{
    std::unordered_map<int, float> map;

    for (int i = 0; i < 10; ++i) {
        map[i] = 99;
    }

    std::iterator<int, float> iter;
    (*iter).first;      // the key value (of type key)
    (*iter).second;     // the mapped value (of type T)
    (*it);              // the "element value" (of type pair<const key, T>)

    iter = map.begin();

    std::cout << iter->first() << std::endl << iter->second() << std::endl;

    return 0;
}
