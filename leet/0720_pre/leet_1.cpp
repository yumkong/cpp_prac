#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(m.find(nums[i]) == m.end())
            {
                m[target - nums[i]] = i;
            }
            else
            {
                result.push_back(m[nums[i]]);
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution solu;
    int arr[] = {1, 2, 3, 4, 9};
    vector<int> inp(arr, arr + 5);
    vector<int> res = solu.twoSum(inp, 10);
    if(!res.empty())
    {
        cout << res.at(0) << " " << res.at(1) << endl;
    }
    return 0;
}
