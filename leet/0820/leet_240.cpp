// searches an int from a matrix of mxn:
// ints in each row are sorted in ascending order from left to right
// ints in each column are sort in ascending order from top to bottom
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row <= 0) return false;
        int col = matrix[0].size();
        if(col <= 0) return false;
        int r = 0, c = col - 1;
        while(c >= 0 && r <= row - 1)
        {
            if(target == matrix[r][c]) return true;
            else if(target < matrix[r][c]) --c;
            else ++r;
        }
        return false;
    }
};

int main()
{
    Solution solu;
    vector<vector<int> > input({ {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, 
                                 {16,17, 18,19,20}, {21,22,23,24,25}});
    cout << solu.searchMatrix(input, 19) << endl;
    //vector<vector<int> > input2({ {1,4}, {2,5} });
    //cout << solu.searchMatrix(input2, 2) << endl;
    return 0;
}
