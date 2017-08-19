// given an integer n, return the number of trailing zeroes in n!
// NOTE: should in O(logn) time
#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int num5 = 0;
        while(n >= 5)
        {
            n /= 5;
            num5 += n;
        }
        return num5;
    }
};

int main()
{
    Solution solu;
    cout << solu.trailingZeroes(30) << endl;
    return 0;
}

