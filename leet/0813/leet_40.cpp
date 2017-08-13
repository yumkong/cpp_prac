//combination sum II => generate two sum to any sum
// given a collection of candidate numbers and a target num, find all unique combinaions which sum to target
// NOTE: all numbers and target will be positive ints, the solu should not contain duplicates
// solu: using dfs and backtracking
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> path;
        dfs_helper(candidates, 0, target, path, res);
        return res;
    }
    void dfs_helper(vector<int>& cand, int cur, int target, vector<int>& path, vector<vector<int> >& res)
    {
        if(target == 0) {res.push_back(path); return; }
        if(target < 0) return;
        for(int i = cur; i < cand.size(); ++i)
        {
            // what if need [1 1 1 6] to get 9 ? => when i == cur, it can be [i] == [i - 1]
            if(i > cur && cand[i] == cand[i - 1]) continue;
            path.push_back(cand[i]);
            dfs_helper(cand, i + 1, target - cand[i], path, res);
            path.pop_back();
        }
    }
};

int main()
{
    Solution solu;
    vector<int> input({10, 1, 2, 7, 6, 1, 5});
    vector<vector<int> > res = solu.combinationSum2(input, 8);
    for(auto& row: res)
    { 
        for(auto& i: row) cout << i << ", ";
        cout << endl;
    }
    return 0;
}
