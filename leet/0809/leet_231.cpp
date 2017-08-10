// given an integer, determine whether it is a power of two (aka. val = 2 ^ x, x = 0, 1, 2, ...)
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (n & (n-1)) == 0;
    }
};

int main()
{
    Solution solu;
    cout << solu.isPowerOfTwo(10) << endl;
    return 0;
}
