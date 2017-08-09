//bitwise and of numbers range
// given a range [m,n] where 0<=m <= n <= 2147483647, return the bitwise AND of all numbers
// in the range
#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0) return 0;
        int prev = 1;
        while(m != n)
        {
            m >>= 1;
            n >>= 1;
            prev <<= 1;
        } 
        return prev * m; 
    }
};

int main()
{
    Solution solu;
    cout << solu.rangeBitwiseAnd(0, 8) << endl;
    return 0;
}
