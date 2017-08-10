// given an int array, where every element appear twice except for one. Find that one.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        for(auto &i: nums) res ^= i;
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,2,3,4,5,6,7,2,1,3,5,7,4}); 
    cout << solu.singleNumber(input) << endl;
    return 0;
}
