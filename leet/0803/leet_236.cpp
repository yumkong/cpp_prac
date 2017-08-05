// given a binary tree, find the lowest common ancester (LCA) of two given nodes in the tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int num = 0;
        TreeNode *res = NULL;
        helper(root, p, q, num, res);
        return res;
    }
    bool helper(TreeNode *root, TreeNode *p, TreeNode *q, int &num, TreeNode *(&res))
    {
        if(!root) return false;
        //if(num >= 2) return true; // to avoid further going down if two nodes have been found
        bool mid = (root == p || root == q);
        if(mid) ++num;
        bool left = helper(root->left, p, q, num, res);
        bool right = helper(root->right, p, q, num, res);
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
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    
    Solution solu;
    TreeNode *res = solu.lowestCommonAncestor(root, root->left, root->left->right->right);
    cout << res->val << endl;
    return 0;
}
