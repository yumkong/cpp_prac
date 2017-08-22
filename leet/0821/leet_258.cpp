// given a non-negative int, repeatedly add all its digits untill the result has only one digit
// NOTE: do it without loop and in O(1) time
// https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
// For base b (decimal case b = 10), the digit root of an integer is:
// dr(n) = 0 if n == 0
// dr(n) = (b-1) if n != 0 and n % (b-1) == 0
// dr(n) = n mod (b-1) if n % (b-1) != 0
// the above 3 can be combined to :
// dr(n) = 1 + (n - 1) % (b - 1)
#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};

int main()
{
    Solution solu;
    cout << solu.addDigits(38) << endl;
    return 0;
}
