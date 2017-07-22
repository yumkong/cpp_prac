// decode string
// the original data not contain any digits, digits are only for repeat nums
//eg1: "3[a2[c]]" => "accaccacc"
#include <iostream>
#include <string> //stoi => only for c++11
#include <stack>
#include <cstdlib> //atoi
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int len = s.size();
        stack<int> numstack;
        stack<string> resstack;
        int i = 0;
        resstack.push("");
        while(i < len)
        {
            char ch = s.at(i);
            if(ch >= '0' && ch <= '9')
            {
                int start = i;
                while(s.at(i+1) >= '0' && s.at(i+1) <= '9') ++i;
                //stoi: string to int conversion
                numstack.push(atoi(s.substr(start, i-start+1).c_str()));
            }
            else if(ch == '[')
            {
                resstack.push("");
            }
            else if(ch == ']')
            {
                string str = resstack.top();  resstack.pop();
                int times = numstack.top();  numstack.pop();
                string sb;
                for(int j = 0; j < times; ++j)
                {
                    sb.insert(sb.end(), str.begin(), str.end());
                }
                sb = resstack.top() + sb;  resstack.pop();
                resstack.push(sb);
            }
            else
            {
                string stmp = resstack.top() + ch;
                resstack.pop();
                resstack.push(stmp);
            }
            ++i;
        }
        return resstack.top();
    }
};

int main()
{
    string s1("2[abc]3[cd]ef");
    Solution solu;
    cout << solu.decodeString(s1) << endl;
    return 0;
}

