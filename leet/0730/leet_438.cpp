// given a string s and a non-empty string p, find all start indices of p's anagrams in s
// NOTE: both length of s and p <= 20100 
// SOLU: use a sliding window
// => compare two long strings must use dictionary
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> charins(26, 0), charinp(26, 0);
        int slen = s.size();
        int plen = p.size();
        if(slen < plen) return res; // empty vector
        for(int i = 0; i < plen; ++i)
        {
            ++charins[s[i]-'a'];
            ++charinp[p[i]-'a'];
        }
        // according to c++ syntax, can directly compare two vector
        if(charins == charinp) res.push_back(0);
        // although i is plen, now compare s[i-plen+1, i] with p
        for(int i = plen; i < slen; ++i)
        {
            --charins[s[i-plen]-'a'];
            ++charins[s[i] - 'a'];
            if(charins == charinp) res.push_back(i-plen+1);
        }
        return res;
    }
};

int main()
{
    string s1("cbaebabacd");
    string s2("abc");
    Solution solu;
    vector<int> res = solu.findAnagrams(s1, s2);
    for(int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;
    return 0;
}
