#include <iostream>
using namespace std;

int count_one(int x)
{
    int cnt = 0;
    for(int i = 0; i < 32; ++i)
    {
        if(x & 1) ++cnt;
        x >>= 1;
    }
    return cnt;
}

int count_convert_bits(int a, int b)
{
    return count_one(a ^ b);
}

int main()
{
    int a = 31, b = 14;
    cout << count_convert_bits(a, b) << endl;
    return 0;
}
