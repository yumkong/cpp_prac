// given two strings s and t, determine if they are isomorphic
// assume both s and t have the same length
// "egg", "add" => true.
// "foo", "bar" => false.
// "paper", "title" => true.
// check an injective mapping => 1 to 1
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mps, mpt;
        int len = s.size();
        for(int i = 0; i < len; ++i)
        {
            if(mps.count(s[i]) == 0 && mpt.count(t[i]) == 0) 
            {
                mps[s[i]] = t[i];
                mpt[t[i]] = s[i];
            }
            else if(mps.count(s[i]) > 0 && mpt.count(t[i]) > 0)
            {
                if(mps[s[i]] != t[i] || mpt[t[i]] != s[i]) return false;
            }
            else return false;
        }
        return true;
    }
};

int main()
{
    Solution solu;
    cout << solu.isIsomorphic("egg", "add") << endl;
    cout << solu.isIsomorphic("aba", "baa") << endl;
    cout << solu.isIsomorphic("ab", "aa") << endl;
    return 0;
}
