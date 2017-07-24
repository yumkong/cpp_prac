// find the minimum number of replacements needed for n (positive int) to become 1 given the following operations:
// (1) n is even:  replace n with n/2
// (2) n is odd:   replace n with either n + 1, or n - 1
#include <iostream>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        return helper(n);
    }
    // return the number of steps to get to 1
    int helper(int n)
    {
        //cout << "n = " << n << endl;
        if(n == 1) return 0;
        if(n == 2) return 1;
        // NOTE when helper(max_int + 1)
        if(n == ~(1 << 31)) return 32; 
        if(n % 2 == 0) return 1 + helper(n / 2);
        else return 1 + min(helper(n + 1), helper(n - 1));
    }
};

int main()
{
    Solution solu;
    //cout << solu.integerReplacement(8) << endl;
    cout << solu.integerReplacement(2147483647) << endl;
    return 0;
}
