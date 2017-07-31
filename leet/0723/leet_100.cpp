// check whether two binary trees are equal (structurally identical and node value the same)
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traverseCompare(p, q);
    }
    bool traverseCompare(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return true; //both empty 
        if(!p || !q) return false; // only one empty
        if(p->val != q->val) return false;
        return traverseCompare(p->left, q->left) && traverseCompare(p->right, q->right);
    }
};

int main()
{
    Solution solu;
    // tree1
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(6);
    root1->right = new TreeNode(5);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(2);
    // tree2
    TreeNode *root2 = new TreeNode(3);
    // compare
    cout << solu.isSameTree(root1, root2) << endl;
    return 0;
}

