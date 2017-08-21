// image smoother
// Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int> > res;
        int row = M.size();
        if(row <= 0) return res;
        int col = M[0].size();
        if(col <= 0) return res;
        // integral image and res
        vector<vector<int> > integralImage(row + 1, vector<int>(col + 1, 0));
        res.assign(row, vector<int>(col, 0));
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                integralImage[r+1][c+1] = integralImage[r+1][c] + integralImage[r][c+1] 
                                        - integralImage[r][c] + M[r][c];
            }
        }
        int up, down, left,right, area;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                up = max(0, r - 1), down = min(row - 1, r + 1), left = max(0, c - 1), right = min(col - 1, c+1);
                area = (down - up + 1) * (right - left + 1);
                res[r][c] = (integralImage[down+1][right+1] - integralImage[down + 1][left] 
                            - integralImage[up][right + 1] + integralImage[up][left]) / area;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int> > input({ {1,1,1}, {1,0,1}, {1,1,1} });
    Solution solu;
    vector<vector<int> > res = solu.imageSmoother(input);
    for(auto& row: res)
    {
        for(auto& i: row) cout << i << " ";
        cout << endl;
    }
    return 0;
}
