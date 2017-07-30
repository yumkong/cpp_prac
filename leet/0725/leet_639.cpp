// find out the total number of ways to decode a string containing 1~9 and '*'
// where 1->'A', 2->'B', ..., 26->'Z', and '*'== 1~9 == 'A' or 'B' or ... 'I'
// length of input string [1, 10^5]
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        long res[2];
        // intepretation ways of the 1st element
        res[0] = helper(s.at(0));
        if(len == 1) return res[0];
        // interpretation ways of the 1st and 2nd elements
        res[1] = res[0] * helper(s.at(1)) + helper(s.at(0), s.at(1));
        for(int j = 2; j < len; ++j)
        {
            long tmp = res[1];
            // num[n] = num[n - 1] * (elem_n) + num[n-2] * (elem_n-1, elem_n)
            // mod the answer with a huge prime number
            res[1] = (res[1] * helper(s.at(j)) + res[0] * helper(s.at(j-1), s.at(j))) % 1000000007;
            res[0] = tmp;
        }
        return (int)res[1];
    }
    // overloaded helper function with 1 argu
    int helper(char ch)
    {
        if(ch == '*') return 9;
        if(ch == '0') return 0;
        return 1;
    }
    // overloaded helper function with 2 argus
    int helper(char ch1, char ch2)
    {
        // ** == 11-26 except 20 because '*' is 1-9
        if(ch1 == '*' && ch2 == '*') return 15;  
        else if(ch2 == '*')
        {
            if(ch1 == '1') return 9; 
            // if larger than 2 cannot combine into a valid letter
            return (ch1 == '2')?6:0;   
        }
        else if(ch1 == '*')
        {
            // when <= 6 can be 1 or 2, otherwise can only be 1
            return ch2 <= '6'?2: 1;
        }
        else //if two digit, has to be [10, 26] in order to be valid
        {
            //
            if(ch1 == '1' || (ch1 == '2' && ch2 >= '0' && ch2 <= '6')) return 1;
            return 0;
        }
    }
};

int main()
{
    Solution solu;
    cout << solu.numDecodings("1*") << endl;
    cout << solu.numDecodings("1234232124*2134") << endl;
    return 0;
}
