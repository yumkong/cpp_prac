// find all possible combinations of k numbers that add up to n, given that only number from 1 to 9 can be used for combination
// and each combination be a unique set of numbers.
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        // using backtracking
        vector<int> tmpres;
        helper(res, tmpres, k, 1, n);
        return res;
    }
    void helper(vector<vector<int> > &res, vector<int> &tmpres, int k, int start, int n)
    {
        if(tmpres.size() == k && n == 0) {res.push_back(tmpres); return;}
        if(tmpres.size() > k) return; // 
        for(int i = start; i <= 9; ++i)
        {
            tmpres.push_back(i);
            // Note here n-i not n-1
            helper(res, tmpres, k, i + 1, n - i);
            tmpres.pop_back();
        }
    }
};

int main()
{
    Solution solu;
    vector<vector<int> > res = solu.combinationSum3(3, 9);
    for(auto &vec: res)
    { 
        cout << "[";
        for(auto &i: vec) cout << i << ", ";
        cout << "]" << endl;
    }
    return 0;
}
