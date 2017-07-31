// given a binary tree and a sum, determine if the tree has a root-to-leaf path s.t. adding up all the values along the path equals to sum
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return helper(root, 0, sum);
    }
    bool helper(TreeNode* root, int cur, int sum)
    {
        if(!root) return false;
        if(!root->left && !root->right) return (cur + root->val == sum)? true : false;
        return helper(root->left, cur + root->val, sum) || helper(root->right, cur + root->val, sum);
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    Solution solu;
    cout << solu.hasPathSum(root, 22) << endl;
    return 0;
}
