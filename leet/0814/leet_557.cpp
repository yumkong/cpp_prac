// given a string reverse the order of chars in each word while still keeping whitespace and initial
// word order
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res;
        int len = s.size();
        int left = 0, right = len - 1;
        while(left < right)
        {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            ++left; --right;
        }
        right = len - 1, left = len - 1;
        for(int i = len - 1; i >= 0; --i)
        {
            if(s[i] == ' ') 
            {
                if(left < right) res += s.substr(left + 1, right - left); 
                res += ' ';
                right = i - 1; 
                left = i - 1; 
            }
            else --left;
        }
        if(left < right) res += s.substr(left + 1, right - left);
        return res;
    }
};

int main()
{
    Solution solu;
    cout << solu.reverseWords("Let's take LeetCode contest") << endl;
    return 0;
}
