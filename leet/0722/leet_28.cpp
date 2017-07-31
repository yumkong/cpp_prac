// return the index of the first occurence of substr in a string, or -1 if not found
// strstr is an already existing func in <cstring>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();
        if(len1 < len2) return -1;
        if(len2 == 0) return 0;
        for(int pos = 0; pos < len1 - len2 + 1; ++pos)
        {
            int i = 0;
            for(i = 0; i < len2; ++i)
            {
                if(haystack.at(pos + i) != needle.at(i)) break;
            }
            if(i >= len2) return pos;
        }
        return -1;
    }
};

int main()
{
    Solution solu;
    string s1("iamyugkongendomosameyole");
    string s2("yo");
    cout << solu.strStr(s1, s2) << endl;
    return 0;
}
