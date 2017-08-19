// find the longest common prefix string amongst an array of strings
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minstrlen = ~(1 << 31); // init as max_int
        int len = strs.size();
        if(len == 0) return "";
        if(len == 1) return strs[0];
        for(int i = 0; i < len; ++i) minstrlen = min(minstrlen, (int)strs[i].size());
        string res;
        for(int k = 0; k < minstrlen; ++k)
        { 
            char anchor = strs[0][k];
            for(int i = 1; i < len; ++i)
            {
                if(strs[i][k] != anchor) return res;
            }
            res.push_back(anchor);
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<string> input({"abc", "abd", "abefd"});
    cout << solu.longestCommonPrefix(input) << endl;
    return 0;
}
