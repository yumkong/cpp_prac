// max product of words length
// given a string array, find the max value of len(word[i]) * len(word[j]) where the two words not 
// share common letters
// ASSUME each word only contain lowercase letters (so only 26 bins => can use an int to represent)
#include <string>
#include <vector>
#include <iostream>
#include <algorithm> //sort
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> intwords(len, 0);
        for(int i = 0; i < len; ++i)
        {
            string tmp = words[i];
            for(int j = 0; j < tmp.size(); ++j) 
            { // even if there is duplicates , it is ok
                intwords[i] |= (1 << (tmp[j] - 'a'));
            }
        }
        int maxlen = 0;
        for(int i = 0; i < len - 1; ++i)
        {
            for(int j = i + 1; j < len; ++j)
            {
                 if((intwords[i] & intwords[j]) == 0 && words[i].size() * words[j].size() > maxlen)
                 { maxlen = words[i].size() * words[j].size(); }
            }
        }
        return maxlen;
    }
};

int main()
{
    vector<string> input({"abcw", "baz", "foo", "bar", "xtfn", "abcdef"});
    Solution solu;
    cout << solu.maxProduct(input) << endl;
    //sort(input.begin(), input.end());
    //for(auto &s: input) cout << s << endl;
    return 0;
}
