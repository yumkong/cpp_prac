// given a positive integer n, find the number of non-negative integer <= n, whose binary representation 
// not contain consecutive ones

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        vector<int> f(32, 0);
        f[0] = 1; // [] => no consecutive ones so its 1
        f[1] = 2; // [0] or [1]
        for(int i = 2; i < 32; ++i) 
        {
            // the count of i-bit binary numbers which contains no consecutive 1's
            f[i] = f[i - 1] + f[i - 2];
        }
        //because only positive integer the 31th bit (1<<30) is enough (32th MSB bit is always 0)
        int i = 30, sum = 0, prev_bit = 0;
        while(i >= 0)
        {
            if((num & (1 << i)) != 0)
            {
                sum += f[i];
                if(prev_bit == 1)
                {
                     // since num itself has consecutive 1's, it is not valid. So minus 1
                     --sum; // to compensate for the sum+1 at the end
                     // no need to count the later, because all of them are invalid:
                     // the preceding bits has consecutive 1's
                     break;
                }
                prev_bit = 1;
            }
            else
            {
                prev_bit = 0;
            }
            --i;
        } 
        return sum + 1; //add the number num itself
    }
};

int main()
{
    Solution solu;
    cout << solu.findIntegers(5) << endl; //should = 5
    return 0;
}
