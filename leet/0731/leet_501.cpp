// find mode (most frequent element) in binary search tree (with duplicates)
// follow up: do without using extra space !!!
#include <iostream>
#include <map>
#include <utility>
#include <vector>
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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        map<int, int> mp; // <val, freq>
        helper(root, mp);
        int maxcnt = 0;
        for(pair<int, int> i:mp)
        {
            if(maxcnt < i.second) maxcnt = i.second;
        }
        for(pair<int, int> i:mp)
        {
            if(maxcnt == i.second) res.push_back(i.first);
        }
        return res;
    }
    void helper(TreeNode *root, map<int, int>& mp)
    {
        if(!root) return;
        ++mp[root->val];
        helper(root->left, mp);
        helper(root->right, mp);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    Solution solu;
    vector<int> res = solu.findMode(root);
    for(auto& i:res) cout << i << " "; 
    cout << endl;
    return 0;
}
