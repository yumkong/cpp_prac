// sort a string in decreasing order of the frequency of characters
//e.g. "tree" => "eert" or "eetr"
// 'a' and 'A' are treated as two different chars, same to other letters
#include <string>
#include <map>
#include <iostream>
#include <utility>
#include <algorithm> // sort
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int len = s.size();
        if(len <= 0) return s;
        map<char, int> mp;
        for(char c: s) ++mp[c];
        //NOTE: initilize vector with map !!!
        vector<pair<char, int> > vp(mp.begin(), mp.end());
        typedef pair<char,int> pci;
        struct myclass{
             bool operator() (pci v1, pci v2) 
             { return v1.second > v2.second; } // desceding order
        } mycomp;
        sort(vp.begin(), vp.end(), mycomp);
        string res;
        for(pair<char, int> tmp: vp) 
        {
            //cout << "come1: 2nd = " << tmp.second << ", 1st = " << tmp.first << endl;
            res.insert(res.end(), tmp.second, tmp.first);
        }
        return res;
    }
};

int main()
{
    Solution solu;
    cout << solu.frequencySort("tree") << endl;
    return 0;
}
