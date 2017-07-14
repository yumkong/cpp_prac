#include <iostream>
#include <string>
#include <cstring> //memset
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len <= 1) return s;
        string longeststr, tmpstr;
        // [0, len-2]
        // for odd palindrome
        for (int i = 0; i < len - 1; ++i)
        {
            tmpstr = findPalindrome(s, i, i);
            if(tmpstr.size() > longeststr.size())
            {
                longeststr = tmpstr;
            }
            tmpstr = findPalindrome(s, i, i+1);
            if(tmpstr.size() > longeststr.size())
            {
                longeststr = tmpstr;
            }
        }
        return longeststr;
    }
    string findPalindrome(string s, int left, int right)
    {
        int len = s.size();
        while(left >= 0 && right <= len - 1 && s[left] == s[right])
        {
            --left; //??
            ++right; //??
        }
        // valid palindraome region should be [left+1, right-1]=> lenght is right-left-2+1
        return s.substr(left + 1, right - left - 1);
    }
    
    // method2: dynamic programming
    string longestPalindrome_dp(string s) {
        int n = s.size();
        if(n <= 1) return s;
        // matrix[j][i] if s[i]->s[j] is a palindrome
        // vector could cause 'Time Limit Error', use native array instead
        bool **matrix = new bool*[n];
        int start = 0, len = 0;
        // dp: 
        // (i==j) => matrix[i][j] = true
        // (i != j) => matrix[i][j] = ( (s[i]==s[j]) && matrix[i-1][j+1] )
        for(int i = 0; i < n; ++i)
        {
            matrix[i] = new bool[i+1];
            //since bool is 1 byte, this is setting each elem of matrix[i] as false
            memset(matrix[i], false, (i+1)*sizeof(bool));
            matrix[i][i] = true;
            for(int j = 0; j < i; ++j)
            {
                // (j == i) => (matrix[i][j] = true)
                // the length from j to i is 2 or 3, then check s[i] == s[j]
                // the length from j to i >= 2, then check s[i] = s[j] && matrix[i-1][j-1]
                if(i == j || (s[j] == s[i] && (i-j < 2 || matrix[i-1][j+1])))
                {
                    matrix[i][j] = true;
                    // update current palindrome
                    if(len < i - j + 1)
                    {
                        start = j;
                        len = i - j + 1;
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i)
        {
            delete [] matrix[i];
        }
        delete [] matrix;
        return s.substr(start, len);
    }
};

int main()
{
    Solution solu;
    string s("swsaabacdfgfdcabaxyz");
    cout << s << " : " << solu.longestPalindrome_dp(s) << endl;
    return 0;
}
