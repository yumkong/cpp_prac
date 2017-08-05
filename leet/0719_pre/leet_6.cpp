// zigzag conversion of a string
//convert("PAYPALISHIRING", 3):
//   P   A   H   N
//   A P L S I I G
//   Y   I   R
// result: output row-wisely: "PAHNAPLSIIGYIR"
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
        // length of a single repeated pattern 
        int onelen = 2*numRows - 2;
        // mp stores row indices
        map <int, int> mp;
        for(int i = 0; i < numRows; ++i)
            mp[i] = i;
        for(int i = numRows; i < onelen; ++i)
            mp[i] = numRows - 2 - (i % numRows);
        vector<char> vc; //empty vector of char
        // vector of char vectors, each char vector stores one row of strings
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
