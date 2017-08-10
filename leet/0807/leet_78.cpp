// given a set of distinct nums, return all possible subsets
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        //int len = nums.size();
        // using backtracking
        vector<int> tmpres;
        helper(res, tmpres, nums, 0);
        return res;
    }
    void helper(vector<vector<int> > &res, vector<int> &tmpres, vector<int>& nums, int start)
    {
        res.push_back(tmpres);
        for(int i = start; i < nums.size(); ++i)
        {
            tmpres.push_back(nums[i]);
            helper(res, tmpres, nums, i + 1);
            tmpres.pop_back();
        }
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,2,3});
    vector<vector<int> > res = solu.subsets(input);
    for(auto &vec: res)
    { 
        cout << "[";
        for(auto &i: vec) cout << i << ", ";
        cout << "]" << endl;
    }
    return 0;
}
