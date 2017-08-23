// remove invalid parentheses
// remove the minimum number of invalid parentheses in order to make the input string valid
// return all possible results
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int len = s.size();
        // method1: BFS
        vector<string> res;
        if(len <= 0) {res.push_back(""); return res; }
        set<string> visited;
        queue<string> qs;
        // 
        visited.insert(s);
        qs.push(s);
        // 
        bool found = false;
        while(!qs.empty())
        {
            s = qs.front();  qs.pop();
            //cout << "s = " << s << endl;
            if(isValid(s)) {res.push_back(s);  found = true; }
            if(found) continue; // to process next one
            // generate all possible states
            for(int i = 0; i < s.size(); ++i)
            {
                // only try to remove left or right paren
                if(s[i] != '(' && s[i] != ')') continue;
                //[0, i-1] + [i+1, end]
                string t = s.substr(0, i) + s.substr(i+1);
                if(visited.count(t) <= 0) // not yet visited
                {
                    qs.push(t);
                    visited.insert(t);
                }
            }
        }
        return res;
    }
    bool isValid(string s)
    {
        int count = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if(c == '(') ++count;
            if(c == ')')
            {
                if(count <= 0) return false;
                else --count;
            }
        }
        return count == 0;
    }
};

int main()
{
    Solution solu;
    vector<string> res = solu.removeInvalidParentheses(")(");
    for(auto& s: res) cout << s << endl;
    return 0;
}
