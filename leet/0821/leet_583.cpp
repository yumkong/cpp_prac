// given word1 and word2, find the minimum number of steps required to make word1 and word2 the same
// where in each step you can delete one character in either string
// NOTE: word length <= 500, chars in words can only be lowercase letters
// solu: using longest common subsequence with memoization
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
		int len1 = word1.size(), len2 = word2.size();
        vector<vector<int> > memo(len1+1, vector<int>(len2 + 1, -1));
		return len1 + len2 - 2 * longCS(word1, word2, len1, len2, memo);
    }
	int longCS(string s1, string s2, int l1, int l2, vector<vector<int> >& memo)
	{
		if(l1 == 0 || l2 == 0) return 0;
		if(memo[l1][l2] >= 0) return memo[l1][l2];
		if(s1[l1 - 1] == s2[l2 - 1]) memo[l1][l2] = 1 + longCS(s1, s2, l1 - 1, l2 - 1, memo);
		else memo[l1][l2] = max(longCS(s1,s2, l1, l2 - 1, memo), longCS(s1, s2, l1 - 1, l2, memo));
		return memo[l1][l2];
	}
};

int main()
{
    Solution solu;
    cout << solu.minDistance("sea", "eat") << endl;
    return 0;
}
