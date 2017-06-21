#include <iostream>
#include <vector>
using namespace std;

int update_bits(int src, int sub, int start, int end)
{
    // mask of the bits in [0, start-1]
    int ret = (1 << start) - 1;
    // using mask to keep the bits in [0, start - 1] as it is, other bits are set as zeros
    ret &= src;
    // sub has a length of end-start+1, so the highest bit goes to [end+1] of src
    return ((src >> (end + 1)) << (end + 1)) | (sub << start) | ret;   
}

int update_bits2(int src, int sub, int start, int end)
{
    // 111111 ... 111
    int upper = ~0;
    // bit 1 is at [end+2] position
    int left = upper - (1 << (end + 1));
    int right = (1 << start) - 1;
    int mask = left | right;
    // the 1st part is to clear all bits to hold sub, the 2nd part is sub shifted to the right position
    return (src & mask) | (sub << start);
}

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

int main()
{
    // n = 10000000000
    int n = 1 << 10;
    // m = 10101
    int m = 21;
    int ans = update_bits(n, m, 2, 6);
    int ans2 = update_bits2(n, m, 2, 6);
    print_binary(n);
    print_binary(m);
    cout << "method1 result: " << endl;
    print_binary(ans);
    cout << "method2 result: " << endl;
    print_binary(ans2);
    return 0;
}
