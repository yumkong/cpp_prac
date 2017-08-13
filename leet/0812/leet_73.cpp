// given an m x n matrix, if an element is 0, set its entire row and column to 0 *** in place ***.
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row <= 0) return;
        int col = matrix[0].size();
        if(col <= 0) return;
        set<int> rowset, colset;
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    rowset.insert(i);
                    colset.insert(j);
                }
            }
        }
        for(auto& i: rowset)
        {
            for(int j = 0; j < col; ++j) matrix[i][j] = 0;
        }
        for(auto& j: colset)
        {
            for(int i = 0; i < row; ++i) matrix[i][j] = 0;
        }
    }
};

int main()
{
    Solution solu;
    vector<vector<int> > matrix({vector<int>({1,1,1,1}),
                                 vector<int>({1,0,1,1}),
                                 vector<int>({1,1,1,1})
                                });
    solu.setZeroes(matrix);
    for(auto& row: matrix)
    {
        for(auto& i: row) cout << i << ", ";
        cout << endl;
    }
    return 0;
}
