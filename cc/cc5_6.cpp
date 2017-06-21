// swap odd and even bits in an integer with as few instructions as possible
// e.g., bit 0 and 1 are swapped, bit 2 and 3 are swapped, etc.
#include <iostream>
#include <vector>
using namespace std;

void print_binary(int src)
{
    vector<int> v;
    int len = 8 * sizeof(int);
    int mask = 1;
    // *** the following operation is like stack
    // save from lower bit to higher bit
    while(len--)
    {
        if(src & mask) v.push_back(1);
        else v.push_back(0);
        mask <<= 1;
    }
    // print from higher bit to lower bit
    while(!v.empty())
    {
        cout << v.back();
        v.pop_back();
    }
    cout << endl;
}

int swap_bit(int a)
{
    return ((a << 1) & 0xaaaaaaaa) | ((a >> 1) & 0x55555555);
}

int main()
{
    int a = (1<<11) + (1<<9) + (1<<6) + (1<<4) + (1<<2) + 1;
    print_binary(a);
    cout << "after swapping odd and even bits: " << endl;
    print_binary(swap_bit(a));
    return 0;
}
