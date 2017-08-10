// preverse bits of a given 32-bit unsigned int
//further: if this function is called many times, how to optimize
#include <iostream>
#include <cstdint> // uint32_t in c++11
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; ++i)
        {
            res <<= 1;
            res += ((n >> i) & 1);
        }
        return res;
    }
};

int main()
{
    Solution solu;
    cout << solu.reverseBits(43261596) << endl;
    return 0;
}
