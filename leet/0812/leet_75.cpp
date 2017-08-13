// given an array with n objects colored red, white or blue, sort them s.t. objects of the same color
// are adjcent, with the colors in the order red (0), white(1) and blue (2)
// NOTE1: should not use sort function
// NOTE2: A rather straight forward solution is a two-pass algorithm using counting sort.
//First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's. Try using an one-pass algorithm with only constant space.
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        // use three pointers
        int p0 = 0, p2 = len - 1;
        //point to the first non-0 
        while(nums[p0] == 0 && p0 < len - 1) ++p0;
        // point to the first non-2
        while(nums[p2] == 2 && p2 >= 1) --p2;
        int mid = p0;
        while(mid <= p2)
        {
            if(nums[mid] == 0) 
            { 
                swap(nums[mid], nums[p0]); 
                ++p0; 
                while(nums[p0] == 0 && p0 < len - 1) ++p0;
                mid = p0;
            }
            else if(nums[mid] == 2) 
            {
                swap(nums[mid], nums[p2]); 
                --p2; 
            }
            else ++mid; // == 1
        }
    }
    void swap(int& x, int& y)
    {
        int tmp = x; 
        x = y;
        y = tmp;
    }
};

int main()
{
    Solution solu;
    vector<int> input({0,1,1,2,0,1,1,2,0,2,0,0});
    solu.sortColors(input);
    for(auto &i: input) cout << i  << " ";
    cout << endl;
    return 0;
}
