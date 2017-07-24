// length of last word
// given a string s consists of upper/lower-case alphabets and empty space ' ', return the length of last word in the string
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        if(len == 0) return 0;
        if(len == 1) return (s.at(0) == ' ')? 0 : 1;
        int last = len - 1; 
        while(last >= 0 && s.at(last) == ' ') --last;
        if(last < 0) return 0;
        int first = last - 1;
        while(first >= 0 && s.at(first) != ' ') --first;
        return last - first;
    }
};

int main()
{
    Solution solu;
    string s("       ");
    cout << solu.lengthOfLastWord(s) << endl;
    return 0;
}
