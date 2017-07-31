// given a list of unique words, find all pairs of distinct indices (i,j) in the list s.t. the 
// concatenation of the words: word[i] + word[j] is a palidrome
// NOTE: the order matter!!!
// the following codes passed, but rank 1.83%!!! too slow ==> need to improve later!!!
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int len = words.size();
        vector<vector<int> > res;
        if(len <= 1) return res;
        for(int i = 0; i < len - 1; ++i)
        {
            int len1 = words[i].size();
            for(int j = i + 1; j < len; ++j)
            {
                int len2 = words[j].size();
                // [i, j] order
                if((len1 == 0 || len2 == 0 || words[i][0] == words[j][len2-1]) && ispalin(words[i]+words[j])) 
                {
                   // cout << words[i] << " + " << words[j] << endl;
                    res.push_back({i, j});
                }
                // [j, i] order
                if((len1 == 0 || len2 == 0 || words[j][0] == words[i][len1-1]) && ispalin(words[j]+words[i])) 
                {
                   // cout << words[j] << " + " << words[i] << endl;
                    res.push_back({j, i});
                }
            }
        }
        return res;
    }
    bool ispalin(string s)
    {
     //   cout << "s = " << s << endl;
        int len = s.size();
        int halflen = len / 2;
        for(int i = 0; i < halflen; ++i)
        {
            if(s[i] != s[len - i - 1]) return false;
        }
        return true;
    }
};

int main()
{
    vector<string> vs({"abcd", "dcba", "lls", "s", "sssll"});
    Solution solu; 
    vector<vector<int> > res = solu.palindromePairs(vs);
    for(auto& i:res) cout << "[" << i[0] << ", " << i[1] << "]" << endl;
    return 0;
}
