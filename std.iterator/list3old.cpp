// stl/list3old.cpp
#include <list>
#include <iostream>
using namespace std;

void print_all_elements(list<char>& coll)
{
    // print all elements;
    // iterate over all elements
    list<char>::const_iterator pos;
    for (auto elem : coll) {
        cout << elem << ' ';
    }
    cout << endl;
}

int main()
{
    list<char> coll;        // list container for character elements

    // append elements from 'a' to 'z'
    for (char c = 'a'; c <= 'z'; ++c) {
        coll.push_back(c);
    }
    
    print_all_elements(coll);
    list<char>::const_iterator pos;
    // make all characters in the list uppercase
    for (pos = coll.begin(); pos != coll.end(); ++pos) {
        *pos = toupper(*pos);
    }
    print_all_elements(coll);

    return 0;
}

