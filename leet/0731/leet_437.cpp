// given a binary tree, find the number of paths summing to a given value
// NOTE: the path does not need to start at the root or end at a leaf
// CORE: every node can be a root and every node can be a leaf
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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        // one path start from root, the 2nd start from root->left, the 3rd from root->right
        return helper(0, root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int helper(int prev, TreeNode *root, int sum)
    {
        if(!root) return 0;
        prev += root->val;
        return (prev == sum) + helper(prev, root->left, sum) + helper(prev, root->right, sum);
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    root->right->right = new TreeNode(11);
    cout << solu.pathSum(root, 8) << endl;
    return 0;
}
