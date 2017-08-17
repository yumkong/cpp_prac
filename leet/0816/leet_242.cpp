// check if two strings is anagram of each other
// assume contain only lower case alphabet
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.size(), len2 = t.size();
        if(len1 != len2) return false;
        vector<int> dict(26, 0);
        for(int i = 0; i < len1; ++i) ++dict[s[i]-'a'];
        for(int i = 0; i < len2; ++i)
        {
            int pos = t[i] - 'a';
            if(dict[pos] == 0) return false;
            else --dict[pos];
        }
        return true;
    }
};

int main()
{
    Solution solu;
    cout << solu.isAnagram("abd", "dcd") << endl;
    return 0;
}
