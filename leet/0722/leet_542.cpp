//given a matrix of 0 and 1, find the distance of the nearest 0 for each element
// the distance between two adjcent cell is 1
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        vector<vector<int> > res; // empty 2d array
        int rowsiz = matrix.size();
        if(rowsiz == 0) return res;
        int colsiz = matrix[0].size();
        if(colsiz == 0) return res;
        vector<int> onerow(colsiz, -1);
        res.assign(rowsiz, onerow); // assign to res a total of rowsiz rows, each row colsiz elems with -1 
        int max_int = ~(1 << 31) - 1; // here we use max_int-1, because some position need to add it by 1
        // forward pass
        for(int r = 0; r < rowsiz; ++r)
        {
            for(int c = 0; c < colsiz; ++c)
            {
                if(matrix[r][c] == 0)  res[r][c] = 0; // distance is 0 if itself is zero
                else
                {
                    int left = max_int, top = max_int;
                    if(r - 1 >= 0) top = res[r - 1][c]; // this position's res val has already assigned
                    if(c - 1 >= 0) left = res[r][c - 1];
                    res[r][c] = min(min(top,left) + 1, max_int);
                }
            }
        }
        // backward pass
        for(int r = rowsiz - 1; r >= 0; --r)
        {
            for(int c = colsiz - 1; c >= 0; --c)
            {
                // if 0 or 1, no need to process since this distance cannot be shortened any more
                if(res[r][c] != 0 && res[r][c] != 1) 
                {
                    int down = max_int, right = max_int;
                    if(r + 1 < rowsiz) down = res[r + 1][c];
                    if(c + 1 < colsiz) right = res[r][c + 1];
                    res[r][c] = min(res[r][c], min(down, right) + 1);
                }
            } 
        }
        return res;
    }
};

int main()
{
    int a1[] = {0,0,0};
    int a2[] = {0,1,0};
    int a3[] = {1,1,1};
    vector<vector<int> > matrix;
    vector<int> arr1(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    vector<int> arr2(a2, a2 + sizeof(a2)/sizeof(a2[0]));
    vector<int> arr3(a3, a3 + sizeof(a3)/sizeof(a3[0]));
    matrix.push_back(arr1);
    matrix.push_back(arr2);
    matrix.push_back(arr3);
    Solution solu;
    vector<vector<int> > res = solu.updateMatrix(matrix);
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[0].size(); ++j)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
