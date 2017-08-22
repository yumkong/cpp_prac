// remove invalid parentheses
// remove the minimum number of invalid parentheses in order to make the input string valid
// return all possible results
#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int len = s.size();
        vector<pair<char, int> > err; // <error char, pos>
        stack<pair<char, int> > st; // same as above vector
        for(int i = 0; i < len; ++i)
        {
            if(s[i] == '(') st.push({s[i], i});
            else if(s[i] == ')')
            {
                if(st.empty()) err.push_back({s[i], i});
                else st.pop();
            }
        }
        // erase all '(' at the end
        while(!st.empty()) 
        {
            s.erase(st.top().second, 1); 
            st.pop();
        }
        vector<string> res;
        int prevpos = -2;
        for(int i = 0; i < err.size(); ++i)
        {
            if(err[i].second == prevpos + 1) 
            {
                prevpos = err[i].second;
                continue;
            }
            int k = 0;
            while(k <= err[i].second)
            {
                if(s[k] == ')') 
                {
                    string stmp = s;
                    stmp.erase(k, 1);
                    res.push_back(stmp);
                    // get rid of consecutive ')'s
                    while(k+1<= err[i].second && s[k+1] == ')') ++k;
                }
                ++k;
            }
            prevpos = err[i].second;
        }
        if(res.empty()) res.push_back(s);
        return res;
    }
};

int main()
{
    Solution solu;
    vector<string> res = solu.removeInvalidParentheses(")(");
    for(auto& s: res) cout << s << endl;
    return 0;
}
