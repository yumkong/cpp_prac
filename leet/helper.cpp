#include <iostream>
#include <cstring> // memset
using namespace std;

int main()
{
    // NOTE traditional c++ cannot new and init an array at the same time
    // but c++11 supports
    //int *arr = new int[10]{666}; // first elem is 666, from 2nd to last: 0
    // for university, we'd better use traditional two steps:
    int *arr = new int[10];
    // last argu: how many bytes
    // set each of the last argu's bytes to 1,as a result: arr[i] = 0x 01 01 01 01, for i=0,1,...,9
    memset(arr, 1, 10*sizeof(int));
    for (int i = 0; i < 10; ++i)
    {
        cout << arr[i] << endl;
    }
    cout << "bool is " << sizeof(bool) << " bytes" << endl;
    delete [] arr;
    return 0;
}
