// 4 sum
// given an array S of n integers, are there 4 ints whose sum equals to [target]?
// return all unique quadruplets
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    }
};

int main()
{
    int a[] = {1, 0, -1, 0, -2, 2};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    vector<vector<int> > res = solu.fourSum(arr, 0);
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
