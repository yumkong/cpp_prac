// given a positive 32-bit integer n, find the smallest 32-bit integer which has the same digits
// and is greater in value than n, return -1 if no such int
// IMPORTANT: nned to consider the max int problem!!!! e.g. 1999999999 => 9199999999 overflow!!!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        // the wrong solu: but this can help solve the problem: compute next larger int with 
        // exactly same number of 0's and 1's digits
        /*
        int tmp = n, cnt = 0;
        while(tmp > 0)
        {
            // must be 01
            if((tmp & 3) == 1) break;
            tmp >>= 1;
            ++cnt;
        }
        // max_int
        if(cnt >= 30) return -1;
        // make 01 => 10
        else return n ^ (3 << cnt);
        */
        int tmp = n;
        vector<int> nums;
        while(tmp > 0)
        {
            nums.insert(nums.begin(), tmp % 10);
            tmp /= 10;
        }
        int len = nums.size();
        if(len <= 1) return -1;
        int start = len - 2;
        while(start >= 0 && nums[start] >= nums[start + 1]) --start;
        //if(start < 0) return -1; // no next permutation
        if(start >= 0)
        {
            int end = len - 1;
            while(nums[end] <= nums[start]) --end;
            // first swap the rightmost ascending pair
            swap(nums[start], nums[end]);
            // then reversing the dececending array after start-th
            // if no possible permutation, revserse the whole string (start = -1)
            reverse(nums.begin() + start + 1, nums.end());
        }
        else return -1; // no such int
        int res = 0, max_int = ~(1 << 31);
        //for(auto& i: nums) cout << i << " ";
        //cout << endl;
        for(auto& i: nums)
        { 
            // pre-stop overflow here
            //cout << "res = " << res << ", max_int = " << (max_int >> 1) << endl;
            // note: here is not ">>1" but "/10"
            if(res > (max_int / 10) || (res == (max_int / 10) && i > 7)) return -1;
            res = res * 10 + i;
        }
        return res;
    }
};

int main()
{
    Solution solu;
    cout << solu.nextGreaterElement(12345) << endl;
    cout << solu.nextGreaterElement(21) << endl;
    cout << solu.nextGreaterElement(1999999999) << endl;
    return 0;
}
