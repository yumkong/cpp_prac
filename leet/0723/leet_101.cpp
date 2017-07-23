// check if a binary tree is a mirror of ifself (symmetric around its center)
#include <iostream>
#include <deque>
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return traverseSymCompare(root->left, root->right);
    }
    bool traverseSymCompare(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return true; // both empty
        if(!p || !q) return false; // only one empty
        if(p->val != q->val) return false; 
        return traverseSymCompare(p->left, q->right) && traverseSymCompare(p->right, q->left);
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);
    cout << solu.isSymmetric(root) << endl;
    return 0;
}
