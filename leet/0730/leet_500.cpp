// given a list of strings, return the words that can be typed using letters on only one row of keyboard
// assume the input string only contain letters of alphabet
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <locale> // toupper
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        int len = words.size();
        if(len <= 0) return res;
        map<char, int> mp; // <letter, letter category(0, 1 or 2)>
        string alphab("QWERTYUIOPASDFGHJKLZXCVBNM");
        int type = 0;
        for(int i = 0; i < 26; ++i)
        {
            if(i == 10 || i == 19) ++type;
            mp[alphab[i]] = type;
        }
        for(int i = 0; i < len; ++i)
        {
            string tmp = words[i];
            int cat = mp[toupper(tmp[0])];
            int j;
            for(j = 1; j < tmp.size(); ++j)
            {
                if(mp[toupper(tmp[j])] != cat) break;
            }
            if(j == tmp.size()) res.push_back(tmp);
        }
        return res;
    }
};

int main()
{
    vector<string> vs({"Hello", "Alaska", "Dad", "Peace"});
    Solution solu;
    vector<string> res = solu.findWords(vs);
    for(string s: res) cout << s << " ";
    cout << endl;
    return 0;
}
