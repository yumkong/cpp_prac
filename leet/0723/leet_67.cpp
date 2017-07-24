// given two binary strings, return their sum as a binary string as well
// "11" + "1" => "100"
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();
        if(len1 == 0) return b;
        if(len2 == 0) return a;
        int i = len1 - 1, j = len2 - 1;
        string incre("0");
        string res("");
        while(i >= 0 && j >= 0)
        {
            // both are 1
            if(a.at(i) == '1' && b.at(j) == '1')
            {
                res = incre + res;
                incre = "1";
            }
            else if(a.at(i) == '1' || b.at(j) == '1') // only one 1
            {
                if(incre == "1")
                {
                    res = "0" + res; // incre still "1"
                }
                else res = "1" + res;
            }
            else // both 0
            {
                res = incre + res;
                incre = "0";
            }
            --i;
            --j;
        } 
        string reststr;
        if(i >= 0) reststr = a.substr(0, i + 1);
        else if(j >= 0) reststr = b.substr(0, j + 1);
        int k = reststr.size() - 1;
        while(k >= 0)
        {
            if(incre == "1" && reststr.at(k) == '1') 
            {
                res = "0" + res; // incre keeps 1
            }
            else if(incre == "1" || reststr.at(k) == '1')
            {
                res = "1" + res;
                incre = "0";
            }
            else
            {
                res = reststr.at(k) + res;
            }
            --k;
        }
        if(incre == "1") res = incre + res;
        return res;
    }
};

int main()
{
    string s1("0");
    string s2("1");
    Solution solu;
    cout << solu.addBinary(s1, s2) << endl;
    return 0;
}
