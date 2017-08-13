// given an int n, generate a square matrix filled with elems from 1 to n^2 in spiral order
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res;
        if(n <= 0) return res;
        if(n == 1) {res.push_back(vector<int>(1,1)); return res; }
        // int the order of right, bottom, left, up, right, ...
        vector<pair<int, int> > direct({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});
        // total moving steps from (0, 0), all initiated as n-1
        vector<int> step(2*n - 1, n - 1);
        int diff = 0;
        for(int i = 2; i < step.size(); ++i)
        {
            step[i] = step[i - 1] - diff;
            diff = diff ^ 1; 
        }
        res.assign(n, vector<int>(n, 1));
        int step_idx = 0, stepnum = 0, r = 0, c = 0, cnt = 1;
        while(1)
        {
            pair<int, int> dir = direct[step_idx % 4];
            stepnum = step[step_idx];
            while(stepnum > 0)
            {
                r += dir.first;  c += dir.second;
                res[r][c] = ++cnt;
                --stepnum;
            }
            ++step_idx;
            if(step_idx >= step.size()) break;
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<vector<int> > res = solu.generateMatrix(2);
    for(auto& row: res)
    {
        for(auto& i: row) cout << i << ", ";
        cout << endl;
    }
    return 0;
}
