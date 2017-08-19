// guess the number higher or lower
// I pick a number from 1 to n, you guess what it is
// every time guess is wrong, tell you whether it is higher or lower
// when guessing a particular number x which is wrong, you pay $x.
// given a paricular n >= 1 find out how much money you need to guarantee a win
// top-down version using dp
// ==> there is also a bottom up way needed to be checked later
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > table(n + 1, vector<int>(n + 1, 0)); 
        return dp_helper(table, 1, n);
    }
    int dp_helper(vector<vector<int> >& tbl, int start, int end)
    {
        if(start >= end) return 0;
        // avoid duplicate computation
        if(tbl[start][end] != 0) return tbl[start][end];
        int res = ~(1 << 31); // max_int
        for(int i = start; i <= end; ++i)
        {
            // iteration
            int tmp = i + max(dp_helper(tbl, start, i - 1), dp_helper(tbl, i + 1, end));
            res = min(res, tmp);
        }
        tbl[start][end] = res;
        return res;
    }
};

int main()
{
    Solution solu;
    cout << solu.getMoneyAmount(10) << endl; // 21
    return 0;
}
