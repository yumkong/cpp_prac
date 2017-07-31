// given a string consisting of lowercase or uppercase letters, find the length of longest palindromes
// that can be built with those letters
// => solu: find all same letter pairs plus 1
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp; // <char, char num>
        for(int i = 0; i < s.size(); ++i)
        {
            ++mp[s[i]];
        }
        int res = 0;
        for(pair<char, int> tmp: mp) res += tmp.second / 2;
        return min(res * 2 + 1, (int)s.size());
    }
};

int main()
{
    string s("abccccdd");
    Solution solu;
    cout << solu.longestPalindrome(s) << endl;
    return 0;
}
