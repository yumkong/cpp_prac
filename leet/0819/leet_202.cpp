// determine if a number is "happy"
// Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0) return false;
        int res = 0;
        set<int> si;
        while(1)
        {
            while(n > 0)
            {
                int tmp = n % 10;
                res += tmp * tmp;
                n /= 10;
            }
            if(res == 1) break;
            else
            {   // no such res before
                if(si.count(res) == 0) si.insert(res);
                else break;
            }
            // reassign n and reset res
            n = res;
            res = 0;
        }
        return res == 1;
    }
};

int main()
{
    Solution solu;
    cout << solu.isHappy(11) << endl;
    return 0;
}
