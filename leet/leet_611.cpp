#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return 0;
        /*int cnt = 0;
        // The follows not work: Time Limit Exceeded
        for(int i = 0; i < len - 2; ++i)
        {
            for(int j = i + 1; j < len - 1; ++j)
            {
                for(int k = j + 1; k < len; ++k)
                {
                    if(nums[i] + nums[j] > nums[k] && nums[j] + nums[k] > nums[i] && nums[k] + nums[i] > nums[j]) 
                        ++cnt;
                }
            }
        }
        return cnt;*/
        // sort in ascending order
        sort(nums.begin(), nums.end());
        //if(len == 3) return (nums[0] + nums[1] > nums[2])? 1: 0;
        int cnt = 0, i, j;
        // i points to largest element to be compared
        for (int k = len - 1; k >= 2; --k)
        {
            //if(nums[i] == 0) continue;
            i = 0, j = k - 1;
            // inspired by java(O(n^2) time in O(1) space!!!
            while(i < j)
            {
                if(nums[i] + nums[j] > nums[k])
                {
                    cnt += j - i;
                    --j;
                }
                else
                {
                    ++i;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    Solution solu;
    int a[] = {2,2,2, 3,4};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    cout << solu.triangleNumber(arr) << endl;
    return 0;
}
