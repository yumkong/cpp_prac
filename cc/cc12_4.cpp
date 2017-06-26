// given an array with all numbers from 1 to N, where N is at most 32,000 (2^15 = 32k)
// the array may have duplicate entries and N is unknown
// with only 4 KB of memory available, how to print all duplicate elments in the array ?
#include <iostream>
using namespace std;

class Bitmap
{
private:
    int *bits;
public:
    Bitmap(int size = 32)
    {
        bits = new int[size / 32 + 1];
    }
    ~Bitmap()
    {
        delete [] bits;
    }
    // if this integer has already appeared
    bool get(int pos)
    {
        // [pos / 32] => pointing to the particular integer range 
        // pos % 31 (pos & 0x1f) => which bit represents this integer in this range
        return (bits[pos / 32] & (1 << (pos & 0x1f))) != 0;
    }
    void set(int pos)
    {
        bits[pos / 32] |= (1 << (pos & 0x1f));
    }
};

void print_duplicates(int a[], int n, int bitsize)
{
    Bitmap bm(bitsize);
    for(int i = 0; i < n; ++i)
    {
        // bitmap starts at 0, number starts at 1
        if(bm.get(a[i] - 1)) cout << a[i] << endl; // print out duplicates
        else bm.set(a[i] - 1);
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 32000, 7, 8, 9, 10, 11, 1, 2, 13, 15, 16, 32000, 11, 5, 8};
    print_duplicates(a, 20, 32000);
    return 0;
}
