// determine whether a string of parentheses is valid
#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        // odd number of parens must be invalid
        if(len == 0 || len % 2 == 1) return false;
        stack<char> cstack;
        for(int i = 0; i < len; ++i)
        {
            char ch = s.at(i);
            if(ch == '(' || ch == '[' || ch == '{')
            {
                cstack.push(ch);
            }
            else // ')', ']' or  '}'
            {
                if(cstack.empty()) return false;
                if((ch == ')' && cstack.top() == '(') || 
                   (ch == ']' && cstack.top() == '[') ||
                   (ch == '}' && cstack.top() == '{') )
                {
                    cstack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(cstack.empty()) return true;    
        else return false;
    }
};

int main()
{
    string s("()[]{}(}");
    Solution solu;
    cout << solu.isValid(s) << endl;
    return 0;
}
