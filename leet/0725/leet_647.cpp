// given a string count how many palindrome substrings in the strting
//eg1: "abd" => 3 ("a","b","d")
//eg2: "aaa" => 6 (1st "a", 2nd "a", 3rd "a", 1st "aa", 2nd "aa", "aaa")
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        int res = 0;
        if(len == 0) return res;
        for(int i = 0; i < len; ++i)
        {
            for(int j = 0; i - j >= 0 && i + j < len && s[i-j] == s[i+j]; ++j) ++res;
            for(int j = 0; i - j - 1 >= 0 && i + j < len && s[i-j-1] == s[i+j]; ++j) ++res;
        }
        return res;
    }
};

int main()
{
    Solution solu;
    cout << solu.countSubstrings("aaa") << endl;
    return 0;
}
