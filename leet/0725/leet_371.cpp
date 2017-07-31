// calculate the sum of two ints without operator '+' and '-'
#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0)
        {
            int sum = a ^ b;
            int carry = ((a & b) << 1);
            a = sum;
            b = carry;
        }
        return a;
    }
};

int main()
{
    Solution solu;
    cout << solu.getSum(11, 22) << endl;
    return 0;
}
