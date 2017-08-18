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
        if(len <= 0) return 0;
        if(s[0] == '0') return 0;
        // dp[i + 1] => from s[0] to s[i], how many intepretion?
        vector<int> dp(len + 1, 1);
        for(int i = 1; i < len; ++i)
        {
            if((s[i-1] == '1' && s[i] != '0') || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6')) dp[i + 1] = dp[i] + dp[i-1];
			else if(s[i-1] == '1' || s[i-1] == '2' && s[i] == '0') dp[i+1] = dp[i-1];
			else if((s[i - 1] >= '3' || s[i-1] == '0') && s[i] == '0') return 0;
            else dp[i+1] = dp[i];
        }
        return dp[len];
    }
};

int main()
{
    Solution solu;
    cout << solu.numDecodings("110") << endl;
    return 0;
}
