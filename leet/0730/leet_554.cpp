// draw a vertical line from the top to the bottom and cross the least bricks
// width sum of bricks in different rows are the same and not exceed INT_MAX
// number of bricks in each row [1, 10000], height of wall [1, 10000]
// total number of bricks not exceed 20000
#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int row = wall.size();
        //if(row == 1) return 0;
        // <current width, num>
        map<int, int> mp;
        for(int r = 0; r < row; ++r)
        {
            int len = wall[r].size();
            int acc = 0;
            for(int j = 0; j < len - 1; ++j) //not need the last brick
            {
                acc += wall[r][j];
                ++mp[acc];
            }
        }
        // in case each row has 1 brick of the same lenght
        if(mp.size() == 0) return row;
        int res = ~(1 << 31);
        for(pair<int, int> tmp: mp)
        {
           // cout << tmp.first << ", " << tmp.second << endl;
            if(res > row - tmp.second) res = row - tmp.second;
        }
        return res;
    }
};

int main()
{
    Solution solu;
    // c++11: 2d array init!!!
    vector<vector<int> > input({ {1}, {1}, {1} });
/*        {1,2,2,1},
        {3,1,2},
        {1,3,2},
        {2,4},
        {3,1,2},
        {1,3,1,1}});*/
    cout << solu.leastBricks(input) << endl;
    return 0;
}
