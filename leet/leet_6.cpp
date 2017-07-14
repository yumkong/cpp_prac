// zigzag conversion of a string
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
		// this border check is very important
		if(len <= 1 || numRows == 1) return s;
        int onelen = 2*numRows - 2;
        map <int, int> mp;
        for(int i = 0; i < numRows; ++i)
            mp[i] = i;
        for(int i = numRows; i < onelen; ++i)
            mp[i] = numRows - 2 - (i % numRows);
        vector<char> vc; //empty vector of char
        vector< vector <char> > vvc(numRows, vc); //numRows of empty vc
        for(int i = 0; i < len; ++i)
            vvc[mp[i%onelen]].push_back(s.at(i));
        string res;
        for(int i = 0; i < numRows; ++i)
            res.insert(res.end(), vvc[i].begin(), vvc[i].end());
        return res;
    }
};

int main()
{
	Solution solu;
	cout << solu.convert("aassd", 5) << endl;
	return 0;
}