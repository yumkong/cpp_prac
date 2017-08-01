// find the sum of all left leaves in a given binary tree
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
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false); // root is viewed as non-left leaf if it is singleton
    }
    int helper(TreeNode *root, bool isleft)
    {
        if(!root) return 0;
        if(!root->left && !root->right) return isleft? root->val: 0;
        return helper(root->left, true) + helper(root->right, false);
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution solu;
    cout << solu.sumOfLeftLeaves(root) << endl;
    return 0;
}
