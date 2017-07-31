// given the root of a tree, find the most frequent subtree sum. If tie, return all the values with 
// highest frequency in any order
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        map<int, int> mp;
        helper(root, res, mp);
        int max_cnt = 0;
        for(pair<int, int> k:mp)
        {
            if(max_cnt < k.second) max_cnt = k.second;
        }
        //cout << "max_cnt = " << max_cnt << endl;
        for(pair<int, int> k:mp)
        {
            //cout << k.first << ", " << k.second << endl;
            if(max_cnt == k.second) res.push_back(k.first);
        }
        return res;
    }
    int helper(TreeNode *root, vector<int>& res, map<int,int>& mp)
    {
        if(!root) return 0;
        int left = helper(root->left, res, mp);
        int right = helper(root->right, res, mp);
        int sum = left + right + root->val;
        ++mp[sum];
        return sum;
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-5);
    vector<int> res = solu.findFrequentTreeSum(root);
    for(auto& i:res) cout << i << " ";
    cout << endl;
    return 0;
}
