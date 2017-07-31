// compute island perimeter
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int> >& grid) {
        int row = grid.size();
        if(row <= 0) return 0;
        int col = grid[0].size();
        if(col <= 0) return 0;
        int type = 0;
        map<int, int> mp;
        vector<int> vi({0xf,7, 0xb, 0xe, 0xd, 6, 5, 3, 9, 0xa, 0xc, 1, 2, 4, 8, 0});
        for(int i = 0; i < 16; ++i)
        {
            if(i == 1 || i == 5 || i == 11 || i == 15) ++type;
            mp[vi[i]] = type;
        }
        int res = 0;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                if(grid[r][c] > 0)  res += mp[getAddr(grid, r, c, row, col)];
                //cout << "r = " << r << ", c = " << c << ", res = " << res << endl;
            }
        }
        return res;
    }
    int getAddr(vector<vector<int> >& grid, int r, int c, int row, int col)
    {
        int top = (r == 0)? 0: grid[r - 1][c];
        int bottom = (r == row - 1)? 0: grid[r+1][c];
        int left = (c == 0)? 0: grid[r][c - 1];
        int right = (c == col - 1)? 0 : grid[r][c+1];
        // counter clock-wise
        return (top << 3) + (left << 2) + (bottom << 1) + right;
    }
};

int main()
{
    Solution solu;
    vector<vector<int> > input({
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    });
    cout << solu.islandPerimeter(input) << endl;
    return 0;
}
