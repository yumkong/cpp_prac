// given a string and a string dictioanry, find the longest string in the dict that can be formed by 
// deleting some characters of the given string
// if there are more than one possible results, return the longest word with the smallest lexicographical
// order, if non, return empty string
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Comp {
    bool operator()(string s1, string s2)
    {
        if(s1.size() != s2.size()) return s1.size() > s2.size();
        else return s1 < s2;
    }
};

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int len = d.size(), slen = s.size();
        // sort the dict in lexicographical order
        sort(d.begin(), d.end(), Comp());
        //vector<vector<int> > memo;
        for(int i = 0; i < len; ++i)
        {
            int dlen = d[i].size();
            // check whether d[i] is subseq of s
            if(isSubseq(d[i], s)) return d[i];
        }
        return "";
    }
    bool isSubseq(string shortstr, string longstr)
    {
	int k = 0;
        for(int i = 0; i < longstr.size() && k < shortstr.size(); ++i)
        {
            if(shortstr[k] == longstr[i]) ++k;
        }
        return k == shortstr.size();
    }
};

int main()
{
    Solution solu;
    vector<string> dict({"ale","apple","monkey","plea"});
    cout << solu.findLongestWord("abpcplea", dict) << endl;
    return 0;
}
