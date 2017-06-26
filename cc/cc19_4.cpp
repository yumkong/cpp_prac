// find the maximum of 2 numbers, not use if-else or comparison operator
#include <iostream>
using namespace std;

int Max1(int a, int b)
{
    int c[2] = {a, b};
    int z = a - b;
    // 1: a < b, 0: a > b 
    z = (z >> 31) & 1;
    return c[z];
}

int Max2(int a, int b)
{
    int z = a - b;
    int k = (z >> 31) & 1;
    return a - k * z;
}

int main()
{
    int a = 5, b = 10;
    cout << Max1(a, b) << endl;
    cout << Max2(a, b) << endl;
    return 0;
}
