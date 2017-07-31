// given a binary tree, find its minimum depth (the number of nodes along the shortest path from the root to leaf)
// Definition for a binary tree node.
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        return helper(root); 
    }
    int helper(TreeNode* root)
    {
        if(!root) return 0;
        // -> has higher priority than !
        if(!root->left) return helper(root->right) + 1;
        if(!root->right) return helper(root->left) + 1;
        return min(helper(root->left), helper(root->right)) + 1;
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
    cout << solu.minDepth(root) << endl;
    return 0;
}
