// given a binary tree, determine whether it is height-balanced (the depth of two subtrees of every node not differ more that 1).
//Definition for a binary tree node.
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int diff = getHeight(root->left) - getHeight(root->right);
        if(diff > 1 || diff < -1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int getHeight(TreeNode* root)
    {
        if(!root) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
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
    cout << solu.isBalanced(root) << endl;
    return 0;
}
