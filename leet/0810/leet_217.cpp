// given an array of ints, find if the array contain duplicates
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i)
        {
            ++mp[nums[i]];
            if(mp[nums[i]] == 2) return true;
        }
        return false;
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,2,3,4,5,6,7,8,9,6});
    cout << solu.containsDuplicate(input) << endl;
    return 0;
}
