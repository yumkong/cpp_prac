// evaluate the value of an arithmetic expression in Reverse Polish Notation
// Valid operators are +, -, *, /. Each operand may be an integer or an expression.
//eg1: ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//eg2: ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int len = tokens.size();
        for(auto& s: tokens)
        {
            // in ascii: +-*/ is less than '0'
            if(s.size() == 1 && s[0] < '0')
            {
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                if(s[0] == '+') st.push(op1 + op2);
                else if(s[0] == '-') st.push(op1 - op2);
                else if(s[0] == '*') st.push(op1 * op2);
                else st.push(op1 / op2);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};

int main()
{
    Solution solu;
    vector<string> input({"4", "13", "5", "/", "+"});
    cout << solu.evalRPN(input) << endl;
    return 0;
}
