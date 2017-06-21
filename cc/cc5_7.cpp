// time complexity is 64n => O(n)
#include <iostream>
#include <cstring>
using namespace std;

//check if a[i]'s j-th bit is 1
int fetch(int a[], int i, int j)
{
    return (a[i] >> j) & 1;
}

// get the whole value for a[i]
int get(int a[], int i)
{
    int ret = 0;
    for(int j = 31; j >= 0; --j)
    {
        ret = (ret << 1) | fetch(a, i, j);
    }
    return ret;
}

int missing(int a[], int n)
{
    bool *b = new bool[n + 1];
    memset(b, false, (n + 1) * sizeof(bool));
    for(int i = 0; i < n; ++i)
    {
        b[get(a, i)] = true;
    }
    int j;
    for(j = 0; j < n + 1; ++j)
    {
        if(!b[j]) break;
    }
    delete [] b;
    return j;
}

int main()
{
    int a[] = {0,1,2,3,4,5,6,7,9,10};
    cout << missing(a, 10) << endl;
    return 0;
}
