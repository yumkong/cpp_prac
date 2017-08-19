// determine whether an int is a power of three (3 ^ x)
// can you solve it without any loop/ recursion ?
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n > 1 && n % 3 == 0) n /= 3;
        return n == 1;
    }
};

int main()
{
    Solution solu;
    cout << solu.isPowerOfThree(89) << endl;
    return 0;
}
