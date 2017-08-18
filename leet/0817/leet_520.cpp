// given a word, judge whether the usage of capitals in it is right or not
// right usages are as follows
// (1) All letters in this word are capitals, like "USA".
// (2) All letters in this word are not capitals, like "leetcode".
// (3) Only the first letter in this word is capital if it has more than one letter, like "Google".
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.size();
        bool lowflag = false;
        if(word[0] > 'Z') lowflag = true;
        for(int i = 1; i < len; ++i)
        {
            if(lowflag && word[i] <= 'Z') return false;
            if(!lowflag && word[i] > 'Z')
            {
                if(i == 1) lowflag = true; // Aa => ok
                else return false;   // AAa =>false
            }
        }
        return true;
    }
};

int main()
{
    Solution solu;
    cout << solu.detectCapitalUse("FasgeE") << endl;
    return 0;
}
