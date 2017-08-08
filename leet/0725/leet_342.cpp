// check whether an integer (signed) is a power of 4
// could do without loops/ recursion
//method 1: explain: First,greater than 0.Second,only have one '1' bit in their binary notation,so we use x&(x-1) to delete the lowest '1',and if then it becomes 0,it prove that there is only one '1' bit.Third,the only '1' bit should be locate at the odd location,for example,16.It's binary is 00010000.So we can use '0x55555555' to check if the '1' bit is in the right place
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        // method 1: an rule of binary representation of n^4 (see the above)
        return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0;
    }
};

int main()
{
    Solution solu;
    cout << solu.isPowerOfFour(16) << endl;
    return 0;
}
