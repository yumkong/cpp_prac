//given an array of size n, find the majority element (the elem that appears more than 
// floor(n/2) times)
// Assume the array is non-empty and the majority element always exist in the array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int res = nums[0], cnt = 1;
        for(int i = 1; i < len; ++i)
        {
            // put this at the beginning is very important !!!
            if(cnt == 0) { res = nums[i]; cnt = 1; }
            else if(nums[i] == res) ++cnt;
            else --cnt;
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,2,1,1,1,1,5,6,7,89});
    cout << solu.majorityElement(input) << endl;
    return 0;
}
