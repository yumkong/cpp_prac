// make a perfect shuffle of a deck of cards
#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a; 
    a = b;
    b = tmp;
}

void RandomShuffle(int a[], int n)
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
    int n = 9;
    int a[] = {1,2,3,4,5,6,7,8,9};
    RandomShuffle(a, n);
    for(int i = 0; i < n; ++i)
    {
        cout << a[i] << endl;
    }
    return 0;
}
