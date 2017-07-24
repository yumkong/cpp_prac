// given an n x n 2D matrix, rotate it by 90 degrees (clockwisely and in-place)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int row = matrix.size();
        if(row == 0) return;
        int col = matrix[0].size();
        if(col == 0) return;
        for(int r = 0; r < row; ++r)
        {
            for(int c = r + 1; c < col; ++c)
            {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
        int i = 0, j = row - 1;
        while(i < j)
        {
            for(int k = 0; k < col; ++k) swap(matrix[k][i], matrix[k][j]);
            ++i;
            --j;
        }
    }
    void swap(int &x, int &y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }
};

int main()
{
    int a1[] = {1,3,6};
    int a2[] = {2,4,6};
    int a3[] = {3,8,32};
    vector<int> arr1(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    vector<int> arr2(a2, a2 + sizeof(a2)/sizeof(a2[0]));
    vector<int> arr3(a3, a3 + sizeof(a3)/sizeof(a3[0]));
    vector<vector<int> > arr;
    arr.push_back(arr1);
    arr.push_back(arr2);
    arr.push_back(arr3);
    Solution solu;
    solu.rotate(arr);
    for(int i = 0; i < arr.size(); ++i)
    {
        for(int j = 0; j < arr[0].size(); ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
