// spiral matrix
// given a matrix of m x n elements, return all elements in spiral order
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res; // empty
        int row = matrix.size();
        if(row == 0) return res;
        int col = matrix[0].size();
        if(col == 0) return res;
        vector<vector<int> > direct(4, vector<int>(2, 0));
        direct[0][1] = 1; //(0,1)
        direct[1][0] = 1; //(1,0)
        direct[2][1] = -1; //(0, -1)
        direct[3][0] = -1;
        int direct_cnt = 0; // 0 1 2 3 0 1 2 3 ...
        int top = 0, bottom = row - 1, left = 0, right = col - 1;
        int r = 0, c = 0; // starting point
        while(true)
        {
            int flag = direct_cnt % 4;
            vector<int> dir = direct[flag];
            for(int i = 0; r + dir[0]*i <= bottom && r + dir[0]*i >= top && 
                           c + dir[1]*i <= right && c + dir[1]*i >= left; ++i)
            {
                res.push_back(matrix[r+dir[0]*i][c+dir[1]*i]);
            }
            if(flag == 0) {++top; ++r; c = right;}
            else if(flag == 1) {--right; --c; r = bottom;}
            else if(flag == 2) {--bottom; --r; c = left;}
            else {++left; ++c; r = top;}
            //stop condition
            if(left > right || top > bottom) break;
            ++direct_cnt;
        }
        return res;
    }
};

int main()
{
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(3, 1));
    matrix.push_back(vector<int>(3, 5));
    matrix.push_back(vector<int>(3, 6));
    matrix.push_back(vector<int>(3, 9));
    Solution solu;
    vector<int> res = solu.spiralOrder(matrix);
    for(int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;
    return 0;
}
