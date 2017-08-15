// two pointers category => here means the two borders of the sliding window
// given two strings s1 and s2, check whether s2 contains the permutation of s1
// NOTE: s1 and s2 only contain lower case letters
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 > len2) return false;
        // only from 'a' to 'z'
        vector<int> s1mp(26, 0);
        vector<int> s2mp(26, 0);
        for(int i = 0; i < len1; ++i)
        {
            ++s1mp[s1[i] - 'a'];
            ++s2mp[s2[i] - 'a'];
        }
        int cnt = 0;
        for(int i = 0; i < 26; ++i)
        {
            if(s1mp[i] == s2mp[i]) ++cnt;
        }
        if(cnt == 26) return true;
        for(int i = 0; i < len2 - len1; ++i)
        {
            int left = s2[i] - 'a', right = s2[i + len1] - 'a';
            ++s2mp[right];
            if(s2mp[right] == s1mp[right]) ++cnt;
            else if(s2mp[right] == s1mp[right] + 1) --cnt; // if previously match, count should -1
            --s2mp[left];
            if(s2mp[left] == s1mp[left]) ++cnt;
            else if(s2mp[left] == s1mp[left] - 1) --cnt;
            if(cnt == 26) return true;
        }
        return false;
    }
};

int main()
{
    Solution solu;
    cout << solu.checkInclusion("ab", "eidboaoo") << endl;
    cout << solu.checkInclusion("ab", "eidbaooo") << endl;
    return 0;
}
