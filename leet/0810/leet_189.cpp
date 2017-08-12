// rotate an array of n elems to the right by k steps
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(k >= len) k = k % len;
        if(k == 0) return;
        // method 1: ok
        //for(int i = 0; i < k; ++i)
        //{
        //    int tmp = nums.back(); nums.pop_back();
        //    nums.insert(nums.begin(), tmp);
        //}
        // method 2: ok => more efficent from last 10% to first 50% 
        if(k == 1) {nums.insert(nums.begin(), nums.back()); nums.pop_back(); }
        else
        {
            vector<int> tmp(nums.begin() + len - k, nums.end());
            nums.erase(nums.begin() + len - k, nums.end());
            nums.insert(nums.begin(), tmp.begin(), tmp.end());
        }
    }
};

int main()
{
    vector<int> input({1,2,3,4,5,6,7});
    Solution solu;
    solu.rotate(input, 3);
    for(auto &i: input) cout << i << " ";
    cout << endl;
    return 0;
}
