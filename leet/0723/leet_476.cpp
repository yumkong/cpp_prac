// given a positive integer, output its complement number
#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        if(num == 0) return 0; // according to the no leading zero bit assumption
        int res = 0;
        for(int i = 0; i < 31; ++i)
        {
            //cout << "num = " << num << endl;
            if(num == 0) break;
            // NOTE: '==' has higher priority than '&' !!! so use () !!! 
            if((num & 0x1) == 0) res += (1 << i);
            //cout << "res = " << res << ", 1<<i = " << (1 << i) << endl;
            num >>= 1; // left shifting by 1 bit
        }
        return res;
    }
};

int main()
{
    Solution solu;
    // 10 => 01: output should be one (no leading zero bit in the integer's binary representation)
    cout << solu.findComplement(2) << endl;
    return 0;
}
