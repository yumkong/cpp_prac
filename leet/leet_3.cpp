//#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    map<char, int> m;
    int maxLen = 0;
    int lastRepeatPos = -1;
    for(int i = 0; i < s.size(); i++)
    {
        //if find duplication, update the lastrepeat pos to this duplication
        // NOTE this is a short-circult design
        if(m.find(s[i]) != m.end() && lastRepeatPos < m[s[i]])
        {
            lastRepeatPos = m[s[i]];
        }
        if(i - lastRepeatPos > maxLen)
        {
            maxLen = i - lastRepeatPos;
        }
        // current index is its dict value
        m[s[i]] = i;
    }
    return maxLen;
}

int main(int argc, char **argv)
{
    string s = "abcabcbb";
    cout << s << ":" << lengthOfLongestSubstring(s) << endl;
    s = "bbbbb";
    cout << s << ":" << lengthOfLongestSubstring(s) << endl;
    s = "bbabcdb";
    cout << s << ":" << lengthOfLongestSubstring(s) << endl;
    
    // read from arguments
    if(argc > 1)
    {
        s = argv[1];
        cout << s << ":" << lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}
