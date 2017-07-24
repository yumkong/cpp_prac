// given an unix-style absolute path for a file, simplify it
#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> res;
        int len = path.size();
        if(len == 0) return path;
        //if(path == "/...") return path;
        int i = 0;
        while(i < len)
        {
            char cur = path.at(i);
            if(cur == '/')
            {
                // when duplicated slashes do nothing
                if(!res.empty() && res.top() == "")
                { }
                else res.push("");
            }
            else if(cur == '.')
            {
                // ".."
                if(i + 1 < len && path.at(i + 1) == '.')
                { 
                    ++i;
                     // for "..."
                    if(i + 1 < len && path.at(i + 1) == '.')
                    {
                        ++i;
                        if(!res.empty() && res.top() == "") res.pop();
                        res.push("...");
                    } 
                    else if(i + 1 == len || (i + 1 < len && path.at(i + 1) == '/'))
                    {
                        // pop "/" first
                        if(!res.empty() && res.top() == "") res.pop(); 
                        // pop the upper path
                        if(!res.empty()) res.pop();
                    }
                    else // if no "/" after "..", put ".." as part of the path
                    {
                        string tmp = "..";
                        if(!res.empty()) 
                        {
                            tmp = res.top() + tmp; res.pop();
                        }
                        res.push(tmp);
                    }
                }
                else if(i+1 == len || (i + 1 < len && path.at(i + 1) == '/'))  // "./" => do nothing
                {}
                else // ".xxx" => "." is part of the name
                {
                    string tmp = ".";
                    if(!res.empty())
                    {
                        tmp = res.top() + tmp; res.pop();
                    }
                    res.push(tmp);
                }
            }
            else // an ordinary character
            {
                string tmp;
                if(!res.empty())
                {
                    tmp = res.top() + cur; res.pop();
                }
                else
                {
                    tmp = cur; 
                }
                res.push(tmp);
            }
            // moving to the next character
            ++i; 
        }
        // delele the tailing "/"
        string output;
        while(!res.empty())
        {
            if(res.top() != "") 
            {
                output = "/" + res.top() + output; 
            }
            res.pop();
        }
        // if empty path, return unix's root path "/"
        if(output == "") output = "/";
        return output;
    }
};

int main()
{
    Solution solu;
    cout << solu.simplifyPath("/a/./b/../../c/") << endl;
    cout << solu.simplifyPath("/home/") << endl;
    cout << solu.simplifyPath("//") << endl;
    cout << solu.simplifyPath("/..hidden") << endl;
    cout << solu.simplifyPath("/.../") << endl;
    cout << solu.simplifyPath("/...") << endl;
    cout << solu.simplifyPath("/.hidden") << endl;
    cout << solu.simplifyPath("/.") << endl;
    return 0;
}
