//return all the 10-letter long sequences that occur more than once in a DNA molecule
// inspired by discussion
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<int, int> mp;
        vector<string> res;
        int feat = 0, i = 0, len = s.size();
        if(len < 10) return res;
        // each string is represented by 3 bits
        for(i = 0; i < 9; ++i) feat = (feat << 3) | (s[i] & 7);
        for(i = 9; i < len; ++i) 
        {
            feat = ((feat << 3) & 0x3fffffff) | (s[i] & 7);
            ++mp[feat];
            if(mp[feat] == 2) res.push_back(s.substr(i - 9, 10));
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<string> res = solu.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(auto &s: res) cout << s << endl;
    return 0;
}
