//given a string representing a non-negative integer [num], remove k digits from it so that the new number is the smallest possible
// the length of num is less than 10002 and >=k, and not contain any leading zeros
//eg1: 1432219, 3 => 1219 
//eg2: 1036, 2 => 3
#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == 0) return num;
        int len = num.size();
        if(len == k)
        {
            string s(1, '0');
            return s; // '0'
        }
        stack<char> cstack;
        char tmp;
        int cnt = 0, res_len = len - k;
        // string.at() return a char type
        int i;
        for(i = 0; i < len; ++i)
        {
            tmp = num.at(i);
            if(cstack.empty()) cstack.push(tmp);
            else //no empty
            {
                while(!cstack.empty() && cstack.top() > tmp && cnt < k) 
                {
                    cstack.pop();
                    ++cnt;
                }
                if((!cstack.empty() || tmp != '0')) 
                { 
                    //cout << "come1" << endl;
                    cstack.push(tmp);
                    //cout << "cstack size = " << cstack.size() << endl;
                }
                if(cnt >= k) break;
            } 
        }
        // generate output res: initialize as the remaining of the input string (even the string is empty)
        string res("");
        //cout << "i = " << i << ", cstack size = " << cstack.size() << endl;
        if(i < len) res = num.substr(i+1);
        while(!cstack.empty())
        {
            res.insert(res.begin(), cstack.top());
            cstack.pop();
            //cout << res << endl;
        }
        // remove heading 0s
        int pos = 0;
        for(int j = 0; j < res.size(); ++j)
        {
            if(res.at(j) == '0') ++pos;
            else break;
        }
        if(pos > 0) res.erase(0, pos); // remove pos '0's starting at 0
        // deal with longer than expected
        if(res.size() > res_len) res = res.substr(0, res_len);
        // deal with empty
        if(res.empty()) 
        {
            string s(1, '0');
            res = s;
        }       
        return res;
    }
};

int main()
{
    Solution solu;
    string s("112");
    cout << solu.removeKdigits(s, 1) << endl;
    string s2("9999999999991");
    cout << solu.removeKdigits(s2, 8) << endl;
    return 0;
}
