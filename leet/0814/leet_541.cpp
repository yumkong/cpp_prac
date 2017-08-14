// given a string and a integer k, reverse the first k characters for every 2k chars counting from the start
// if there are less than k chars left, reverse all of them
// NOTE: the string contains lower English letters only, len of given string and k is in [1, 10000]
#include <string>
#include <iostream>
#include <algorithm> // reverse
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        if(k == 1) return s;
        for(int left = 0; left < s.size(); left += 2*k)
        {
            // note that begin() and end() can be compared in sequential container
            reverse(s.begin() + left, min(s.begin() + left + k, s.end()));
        }
        return s;
    }
};

int main()
{
    Solution solu;
    cout << solu.reverseStr("abcdefg", 2) << endl;
    return 0;
}
