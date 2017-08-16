// takes a string as input and reverse only the vowels of a string
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> pos; // keep all positions of vowels
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
               s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                pos.push_back(i);
        }
        int l = 0, r = pos.size() - 1;
        while(l < r) 
        {
            swap(s[pos[l]], s[pos[r]]);
            ++l; --r;
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
    cout << solu.reverseVowels("leetcode") << endl;
    return 0;
}
