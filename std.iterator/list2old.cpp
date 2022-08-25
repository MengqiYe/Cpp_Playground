// stl/list2old.cpp
#include <list>
#include <iostream>
using namespace std;

int main()
{
    list<char> coll;        // list container for character elements

    // append elements from 'a' to 'z'
    for (char c = 'a'; c <= 'z'; ++c) {
        coll.push_back(c);
    }

    // print all elements;
    // -iterate over all elements
    list<char>::const_iterator pos;
    for (auto elem : coll) {
        cout << elem << ' ';
    }
    cout << endl;

    return 0;
}

