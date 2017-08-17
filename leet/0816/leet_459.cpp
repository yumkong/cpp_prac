// given a non-empty string, check if it can be constructed by taking a substring of it and appending 
// multiple copies of the substring
// e.g.: abab => true(substring is "ab")
// note: the English letters <= 10000 in length
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // dp[i+1] => the maximum number of chars that the string is repeating itseelf up to position i
        // e.g."abcabc" [0 0 0 0 1 1 1 ] 
        int i = 1, j = 0, len = s.size();
        vector<int> dp(len + 1, 0);
        while(i < len)
        {
            if(s[i] == s[j]) dp[++i] = ++j;
            else if(j == 0) ++i;
            else j = dp[j];
        }
        for(auto& i: dp) cout << i << ": " << dp[i] << endl;
        return dp[len] && dp[len] % (len - dp[len]) == 0;
    }
};

int main()
{
    Solution solu;
    cout << solu.repeatedSubstringPattern("abab") << endl;
    return 0;
}
