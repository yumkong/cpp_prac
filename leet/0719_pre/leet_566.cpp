#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
        int row = nums.size();
        int col = nums[0].size();
        if(row * col != r * c || (row == r && col == c)) return nums;
        vector<int> row_vec, tmp_rec;
        for(int i = 0; i < row; ++i) row_vec.insert(row_vec.end(), nums[i].begin(), nums[i].end());
        vector<vector<int> > res;
        for(int i = 0; i < r; ++i) 
        {
            tmp_rec.assign(row_vec.begin() + i*c, row_vec.begin() + (i+1)*c);
            res.push_back(tmp_rec);
        }
        return res;
    }
};

int main()
{
    int a1[] = {1,2};
    int a2[] = {5,66};
    
    vector<int> v1(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    vector<int> v2(a2, a2 + sizeof(a2)/sizeof(a2[0]));
    vector<vector<int> > arr;
    arr.push_back(v1);
    arr.push_back(v2);
    Solution solu;
    solu.matrixReshape(arr, 1, 4);
    return 0;
}
