//given two words, find the minimum steps to convert word1 to word2
// each operation is counted as 1 step:
// (1) insert a char
// (2) delete a char
// (3) replace a char
// dp problem: define state dp[i][j] the minimum number of operations to convert word1[0...i-1] to word2[0 ...j-1]
// a): corner case: to convert a string to an empty string (j == 1) requires at least i operation:
// -- dp[i][0] = i,
// -- dp[0][j] = j,
// b): general case: convert an non-empty str to another non-empty str. 
// => break down to sub-problems. Suppose dp[i-1][j-1] is known, now consider word1[i - 1] to word2[j - 1]
// -- if they equal, no operation needed: dp[i][j] = dp[i-1][j-1]
// -- if not equal, three cases
//    -- replace word1[i-1] by word2[j-1] plus from word1[0 ...i-2] to word2[0 ...j-2](dp[i][j] = dp[i-1][j-1] + 1)
//    -- delete word1[i-1] plus from word1[0 ...i-2] to word2[0 ...j-1] (dp[i][j] = dp[i-1][j] + 1)
//    -- insert word2[j-1] after word1[0 ...i-1] plus from word1[0 ...i-1] + word2[j-1] to word2[0 ...j-2] + word2[j-1] (dp[i][j] = dp[i][j-1] + 1)
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
        // dp-style is always <= instead of < len, because they use [0][x] and [x][0] as border initialization
        // i = 1 instead of i = 0 to start from the real first element
        for(int i = 1; i <= len1; ++i) dp[i][0] = i;
        for(int i = 1; i <= len2; ++i) dp[0][i] = i;
        for(int i = 1; i <= len1; ++i)
        {
            for(int j = 1; j <= len2; ++j)
            {
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;// to min operation
            }
        }
        return dp[len1][len2];
    } 
};

int main()
{
    Solution solu;
    cout << solu.minDistance("dash", "advertishment") << endl;
    return 0;
}
