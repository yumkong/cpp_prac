// given a binary tree each node represent the money, but cannot get the money from directly linked node (aka. father-left or father-right), find the way to get the maximum amount of money
// NOTE: for tree always remember to recursion left tree and right tree
#include <map>
#include <iostream>
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
    int rob(TreeNode* root) {
        map<TreeNode *, int> mp; //
        return helper(root, mp);
    }
    int helper(TreeNode *root, map<TreeNode *, int> &mp)
    {
        if(!root) return 0;
        //cout << "come1: " << root->val << endl;
        if(mp.count(root) > 0) return mp[root]; // save duplication computation
        int val = 0;
        //cout << "come2" << endl;
        if(root->left) val += helper(root->left->left, mp) + helper(root->left->right, mp);
        if(root->right) val += helper(root->right->left, mp) + helper(root->right->right, mp);
        val = max(val + root->val, helper(root->left, mp) + helper(root->right, mp));
        mp[root] = val; // build the hashmap
        return val; // the max money
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << solu.rob(root) << endl;
    return 0;
}
