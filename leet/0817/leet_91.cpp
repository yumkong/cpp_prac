// a message containing letters from A-Z is encoded to numbers using : 'A' -> 1, 'B' -> 2, ... 'Z' -> 26
// given a encoded message containing digits, determine the total number of ways to decode it.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        // dp[i + 1] => from s[0] to s[i], how many intepretion?
        vector<int> dp(len + 1, 1);
        for(int i = 1; i < len; ++i)
        {
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) dp[i + 1] = dp[i] * 2;
            else dp[i+1] = dp[i];
        }
        return dp[len];
    }
};

int main()
{
    Solution solu;
    cout << solu.numDecodings("123345232") << endl;
    return 0;
}
