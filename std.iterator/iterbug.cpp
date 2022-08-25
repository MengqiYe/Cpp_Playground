//
// Created by elsey on 2022/7/6.
//
// stl/iterbug.cpp

#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> coll1;   // empty collection
    vector<int> coll2;   // empty collection

    // RUNTIME ERROR:
    // - beginning is behind the end of the range
    vector<int>::iterator pos = coll1.begin();
    reverse(++pos, coll1.end());
    // insert elements from 1 to 9 into coll1
    for (int i = 1; i <= 9; ++i) {
        coll1.push_back(i);
    }

    // RUNTIME ERROR:
    // - overwriting nonexisting elements
    copy(coll1.cbegin(), coll1.cend(),      // source
         coll2.begin());                    // destination

    // RUNTIME ERROR:
    // - overwriting nonexisting elements
    // - cbegin() and cend() refer to different  collections
    copy(coll1.cbegin(), coll2.cend(),      // source
         coll1.end());                    // destination

    // Note that because these errors occur at runtime, not at compile time, they cause undefined behavior.
    // There are many ways to make mistakes when using the STL, and the STL is not required to protect you from yourself.
    // Thus, it is a good idea to use a "safe" STL, at least during software development.


}