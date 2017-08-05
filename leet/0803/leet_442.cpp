// given an integer array: 1 <= a[i] <= n (n = array size), some appear **twice** and others **once**
// find all elements that appear twice in O(n) time without extra space
#include <iostream>
#include <vector>
#include <algorithm> //find
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        for(int i = 0; i < len; ++i)
        {
            //if(nums[i] == i + 1) continue;
            //while(nums[nums[i] - 1] != nums[i]) swap(nums[i], nums[nums[i] - 1]);
            //if(nums[i] != i + 1 && find(res.begin(), res.end(), nums[i])==res.end()) res.push_back(nums[i]);
            if(nums[(nums[i] - 1) % len] > len) 
            {
                int tmp = (nums[i] % len == 0)? len: nums[i]%len;
                res.push_back(tmp);
            }
            else nums[(nums[i] - 1) % len] += len;
        }
        return res;
    }
    //void swap(int &x, int &y)
    //{
    //    int tmp = x;
    //    x = y;
    //    y = tmp;
    //}
};

int main()
{
    Solution solu;
    vector<int> arr({4,3,2,7,8,2,3,1});
    vector<int> res = solu.findDuplicates(arr);
    for(auto &i: res) cout << i << " ";
    cout << endl;
    return 0;
}
