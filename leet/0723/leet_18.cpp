// 4 sum
// given an array S of n integers, are there 4 ints whose sum equals to [target]?
// return all unique quadruplets
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // in ascending order
        int len = nums.size();
        vector<vector<int> > res;
        if(len < 4) return res; // empty vvi
        if(len == 4)
        {
            if(nums[0] + nums[1] + nums[2] + nums[3] == target)
            {
                 res.push_back(nums);
            }            
            return res;
        }
        int sum;
        int i = 0;
        for(int i = 0; i < len - 3; ++i)
        {
            for(int j = i + 1; j < len - 2; ++j)
            {
                int tmp = target -nums[i] - nums[j];
                int first = j + 1, last = len - 1;
                while(first < last)
                {
                    //cout << "come3, first = " << first << ", last = " << last << endl;
                    sum = nums[first] + nums[last];
                    // sum of 3 vals are less than zero
                    if(sum < tmp) ++first;
                    else if(sum > tmp) --last; // sum larger than zero
                    else // here is a dead loop
                    {
                        vector<int> tmpvec(4, 0);
                        tmpvec[0] = nums[i]; // smallest
                        tmpvec[1] = nums[j];
                        tmpvec[2] = nums[first]; //middle
                        tmpvec[3] = nums[last]; // largest
                        res.push_back(tmpvec);
                        // fix the bug: find another good group
                        ++first;
                        --last;
                        // remove duplicates
                        while(first < len && nums[first] == nums[first - 1]) ++first;
                        while(last > i && nums[last] == nums[last + 1]) --last;
                    }
                }    
                while(j < len - 2 && nums[j] == nums[j + 1]) ++j;
            }
            while(i < len - 3 && nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }
};

int main()
{
    int a[] = {1, 0, -1, 0, -2, 2};  //0
    //int a[] = {-1, 0, 1,2,-1,-4};  //-1
    //int a[] = {-3, -2,-1,0,0,1,2,3}; // 0
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
