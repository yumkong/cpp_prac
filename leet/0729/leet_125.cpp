// given a string, determine if is a palindrome, consider only alphanumeric chars and ignoring cases
#include <string>
#include <iostream>
#include <locale>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        if(len <= 1) return true;
        int start = 0, end = len - 1;
        while(start < end)
        {
            //int flag = 0;
            char left = s.at(start);
            char right = s.at(end);
            //##NOTE can use isalnum(left)==true instead
            while(!(left >= 'a' && left <= 'z') && !(left >= 'A' && left <= 'Z') && !(left >= '0' && left <= '9')) 
            {
                ++start;
                left = s.at(start);
            }
            //else ++start;
            while(!(right >= 'a' && right <= 'z') && !(right >= 'A' && right <= 'Z') && !(right >= '0' && right <= '9'))
            {
                --end;
                right = s.at(end);
            }
            //if(flag == 2)
            //{
                // ###NOTE### here cannot use the following because '0' = 48, and 'P' == 80, their diff is just 32!!!
                //if(left == right || left - right == (char)32 || right - left == (char)32)
                if(toupper(left) == toupper(right))
                {   //debug
                    //cout << "match: start = " << start << ", end = " << end << endl;
                    ++start;
                    --end;
                }
                else return false;
            //}
        }
        return true;
    }
};

int main()
{
    Solution solu;
    cout << solu.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solu.isPalindrome("0P") << endl;
    return 0;
}
