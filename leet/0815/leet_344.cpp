// return a inversed string
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int len = s.size();
        int l = 0, r = len - 1;
        while(l < r)
        {
            swap(s[l++], s[r--]);
        }
        return s;
    }
    void swap(char& x, char& y)
    {
        char tmp = x;
        x = y;
        y = tmp;
    }
};

int main()
{
    Solution solu;
    cout << solu.reverseString("hello") << endl;
    return 0;
}
