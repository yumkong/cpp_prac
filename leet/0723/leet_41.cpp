// given an unsorted integer array, find the first missing positive integer
// eg1: [1,2,0] => 3
// eg2: [3,4,-1,1] => 2
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; ++i)
        {   // assume that no element in nums is larger than len
            // NOTE: here is while instead of if to GUARANTEE that all the elems in nums[i]
            // which is (0, len] has been put the right position
            while(nums[i] > 0 && nums[i] <= len && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }  
        for(int i = 0; i < len; ++i)
        {
            if(nums[i] != i + 1) return i + 1;
        }
        return len + 1;
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
    int a[] = {3,4,-1, 1};
    vector<int> arr(a, a+ sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.firstMissingPositive(arr) << endl;
    for(int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
