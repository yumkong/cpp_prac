// given a string, find the 1st non-repeating character in it and return its index, if not exist return -1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.size();
        if(len == 0) return -1;
        vector<int> frq(26, 0);
        for(int i = 0; i < len; ++i) ++frq[s[i] - 'a'];
        for(int i = 0; i < len; ++i) 
        {
            if(frq[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};

int main()
{
    Solution solu;
    cout << solu.firstUniqChar("loveleetcode") << endl;
    return 0;
}
