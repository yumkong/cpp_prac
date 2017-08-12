// given a collection of ints with possible duplicates, return all subsets
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        // sorting is important due to DUPLICATES
        sort(nums.begin(), nums.end());
        set<vector<int> > st;
        vector<int> tmpres;
        helper(nums, st, tmpres, 0);
        vector<vector<int> > res(st.begin(), st.end());
        return res;
    }
    void helper(vector<int>& nums, set<vector<int> > &res, vector<int> &tmpres, int start)
    {
        res.insert(tmpres);
        for(int i = start; i < nums.size(); ++i)
        {
            tmpres.push_back(nums[i]);
            helper(nums, res, tmpres, i + 1);
            tmpres.pop_back();
        }
    }
};

int main()
{
    Solution solu;
    vector<int> input({4,4,4,1,4});
    vector<vector<int> > res = solu.subsetsWithDup(input);
    for(auto &row: res)
    {   
        cout << "[";
        for(auto &i: row) cout << i << ", ";
        cout << "]" << endl;
    }
    return 0;
}
