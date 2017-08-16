// given string s1 (ransom note), s2(magazine), check whether s1 can be constructed from s2
// ASSUME: both strings have only lower case letters
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len1 = ransomNote.size(), len2 = magazine.size();
        vector<int> dict(26, 0);
        for(int i = 0; i < len2; ++i) ++dict[magazine[i] - 'a'];
        for(int i = 0; i < len1; ++i)
        {
            int pos = ransomNote[i] - 'a';
            if(dict[pos] == 0) return false;
            else --dict[pos];
        }
        return true;
    }
};

int main()
{
    Solution solu;
    cout << solu.canConstruct("aa", "aab") << endl;
    return 0;
}
