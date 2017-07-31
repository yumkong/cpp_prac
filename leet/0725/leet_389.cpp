// given two strings s and t which consist of just lowercase letters
// string t is generated by random suffling string s and then add one more letter at random position
// find the letter added in t
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int len = s.size();
        if(len == 0) return t.at(0); // the only letter in t
        sort(s.begin(), s.end()); // ascending order
        sort(t.begin(), t.end()); // ascending order
        for(int i = 0; i < len; ++i)
        {
            if(s.at(i) != t.at(i)) return t.at(i);
        }
        // in case the new letter is at the end
        return (char)t.at(len);

        //##### a better method
        //char r = 0;
        //for(char ch: s) r ^= ch;
        //for(char ch: t) r ^= ch;
        //return (int)r;
    }
};

int main()
{
    Solution solu;
    cout << solu.findTheDifference("adbc", "abcde") << endl;
    return 0;
}
