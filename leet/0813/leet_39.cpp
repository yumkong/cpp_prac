// given a set of candidate numbers (no duplicates) and a targe num, 
//find all unique combinations which sums to target
// NOTE the same number may be chosen from the set unlimited number of times
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            int k = 1;
            while(k * cand[i] <= target)
            {
                path.insert(path.end(), k, cand[i]);
                dfs_helper(cand, i + 1, target - k * cand[i], path, res);
                int tmpk = k;
                while(tmpk > 0) {path.pop_back(); --tmpk; }
                ++k;
            }
        }
    }
};

int main()
{
    Solution solu;
    vector<int> input({2, 3, 6, 7});
    vector<vector<int> > res = solu.combinationSum(input, 17);
    for(auto& row: res)
    { 
        for(auto& i: row) cout << i << ", ";
        cout << endl;
    }
    return 0;
}
