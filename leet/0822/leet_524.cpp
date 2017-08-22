// given a string and a string dictioanry, find the longest string in the dict that can be formed by 
// deleting some characters of the given string
// if there are more than one possible results, return the longest word with the smallest lexicographical
// order, if non, return empty string
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        
    }
};

int main()
{
    Solution solu;
    vector<string> dict({"ale","apple","monkey","plea"});
    cout << solu.findLongestWord("abpcplea", dict) << endl;
    return 0;
}
