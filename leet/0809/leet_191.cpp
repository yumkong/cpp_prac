// return the number of "1" bits an unsigned integer has
#include <cstdint> // uint32_t => only in c++11
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n > 0)
        {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }
};

int main()
{
    Solution solu;
    cout << solu.hammingWeight(11) << endl;
    return 0;
}
