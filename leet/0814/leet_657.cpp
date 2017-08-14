// judge if a robot makes a circle (moves back to its original place) given four moves: R,L,U,D
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int len = moves.size();
        int lnum = 0, rnum = 0, unum = 0, dnum = 0;
        for(int i = 0; i < len; ++i)
        {
            if(moves[i] == 'L') ++lnum;
            else if(moves[i] == 'R') ++rnum;
            else if(moves[i] == 'U') ++unum;
            else ++dnum;
        }
        return (lnum == rnum) && (unum == dnum);
    }
};

int main()
{
    Solution solu;
    cout << solu.judgeCircle("LL") << endl;
    cout << solu.judgeCircle("UD") << endl;
    return 0;
}
