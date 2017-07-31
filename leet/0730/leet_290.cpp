// given a pattern (contains only lowercase letters) and a string (non-empty contains lower case letters separated by a single space)
// check if the str follows the same pattern
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int len = pattern.size();
		int len2 = str.size();
		map<char, string> mp;
		int start = 0, end = 1;
		for(int i = 0; i < len; ++i)
        {
			if(i == len - 1)
				end = len2;
			else
				while(str[end] != ' ') ++end;
			if(mp.count(pattern[i]) == 0)
			{
				mp[pattern[i]] = str.substr(start, end-start);
			}  
			else 
			{
				if(mp[pattern[i]] != str.substr(start, end-start)) return false;
			}	
			//debug
			cout << str.substr(start, end-start) << endl;
			start = end + 1; // point to the start of next word
			end = start + 1;
		}
		return true;
    }
};

int main()
{
    Solution solu;
    cout << solu.wordPattern("abba", "dog cat cat dog") << endl;
    return 0;
}
