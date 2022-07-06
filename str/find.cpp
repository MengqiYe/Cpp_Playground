//
// Created by elsey on 2022/3/4.
//
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char * a = "11mish_1_0";
    string a_str = a;
    int pos = a_str.find("mishk");

    cout << pos << endl;

    return 0;
}