// find lowest common ancestor of two given nodes in the BST
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res = NULL;
        helper(root, p, q, res);
        return res;
    }
    bool helper(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *(&res))
    {
        if(!root) return false;
        bool mid = (root == p || root == q);
        bool left = helper(root->left, p, q, res);
        bool right = helper(root->right, p, q, res);
        if((left && right) || (mid && (left || right))) 
        {
            res = root;
           // cout << "left = " << left << ", right = " << right << ", mid = " << mid << endl; 
        }
        //cout << "root = " << root->val << ", num = " << num << endl;
        return (mid || left || right);
    }
};

int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    
    Solution solu;
    TreeNode *res = solu.lowestCommonAncestor(root, root->left, root->left->right->right);
    cout << res->val << endl;
    return 0;
}
