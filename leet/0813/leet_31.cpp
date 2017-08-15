// next permutation
// rearranges number into the lexicographically next greater permutation of numbers
// if impossible, return lowest posible order
// NOTE: replacement must be done in-place with O(1) memory
#include <iostream>
#include <vector>
#include <algorithm> // reverse, swap
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        int start = len - 2;
        while(start >= 0 && nums[start] >= nums[start + 1]) --start;
        //if(start < 0) return -1; // no next permutation
        if(start >= 0)
        {
            int end = len - 1;
            while(nums[end] <= nums[start]) --end;
            // first swap the rightmost ascending pair
            swap(nums[start], nums[end]);
        }
        // then reversing the dececending array after start-th
        // if no possible permutation, revserse the whole string (start = -1)
        reverse(nums.begin() + start + 1, nums.end());
    }
};

int main()
{
    vector<int> input({1,1}); //({1,2,5,4,3,0});
    Solution solu;
    solu.nextPermutation(input);
    for(auto& i: input) cout << i << " ";
    cout << endl;
    return 0;
}

