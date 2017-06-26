// randomly generate a set of m integers from an array of size n
// each element must have equal probablity of being chosen
#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void PickRandomM(int a[], int n, int m)
{
    for(int i = 0; i < n; ++i)
    {
        // generate random number between i to n - 1
        int j = rand() % (n - i) + i;
        swap(a[i], a[j]);
    }
}

int main()
{
    // make seed at the main func, and rand() can be used in and sub-func 
    srand((unsigned)time(0));
    // m is the number to be picked up
    int n = 9, m = 5;
    int a[] = {1,2,3,4,5,6,7,8,9};
    // *** just shuffle a[] and then pick up the first m elems
    PickRandomM(a, n, m);
    for(int i = 0; i < m; ++i)
    {
        cout << a[i] << endl;
    }
    return 0;
}

