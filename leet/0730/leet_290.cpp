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
        if(len == 0 || len2 == 0) return false;
	map<char, string> mp;
        map<string, char> mp2;
	int start = 0, end = 1;
	for(int i = 0; i < len; ++i)
        {
	    if(i == len - 1) end = len2;
	    else
  	    {
     	        while(str[end] != ' ' && end != len2) ++end;
                // here added in case str is invalid (not contain as many as len-1 spaces)
                if(end >= len2) return false;
            }
	    if(mp.count(pattern[i]) == 0)
	    {
		mp[pattern[i]] = str.substr(start, end-start);
	    }  
	    else 
	    {
		if(mp[pattern[i]] != str.substr(start, end-start)) return false;
	    }	
	    //debug
	    //cout << str.substr(start, end-start) << endl;
	    start = end + 1; // point to the start of next word
	    end = start + 1;
	}
        for(auto &i: mp)
        {
            mp2.insert({i.second, i.first});
        }
        // make sure it is a bijection
	return mp.size() == mp2.size();//true;
    }
};

int main()
{
    Solution solu;
    cout << solu.wordPattern("abba", "dog cat cat dog") << endl; // false
    return 0;
}
