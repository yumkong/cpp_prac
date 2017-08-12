// given two words, and a dictionary's word list, find all shortest transformation sequence from
// begin word to endword s.t. 
// (1) only 1 letter can be changed
// (2) each transformed word must exist in the word list
// NOTE: all words have the same length
//       all words contain only lowercase chars
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
    }
};

int main()
{
    Solution solu;
    string beg("hit");
    string end("cog");
    vector<string> wordlist({"hot","dot","dog","lot","log","cog"});
    vector<vector<string> > res = solu.findLadders(beg, end, wordlist) << endl;
    for(auto &i: res) cout << i << " ";
    cout << endl;
    return 0;
}
