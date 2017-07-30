// given a string, determine if is a palindrome, consider only alphanumeric chars and ignoring cases
#include <string>
#include <iostream>
#include <locale> // isalnum, toupper (covert to upper case)
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) 
        {  // Move 2 pointers from each end until they collide
           // letter('a'-'z', 'A'-'Z') or number('0' -'9')
           while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
           while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
           if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
        }
        return true;
    }
};

int main()
{
    Solution solu;
    //cout << solu.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solu.isPalindrome("0P") << endl;
    return 0;
}
