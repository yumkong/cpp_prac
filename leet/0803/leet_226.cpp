// invert a binary tree
#include <iostream>
#include <queue>
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
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
    void helper(TreeNode *root)
    {
        if(!root) return;
        if(root->left || root->right) swaplr(root);
        if(root->left) helper(root->left);
        if(root->right) helper(root->right);
    }
    void swaplr(TreeNode *root)
    {
        TreeNode *tmp;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    //root->left->right->left = new TreeNode(3);
    //root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution solu;
    TreeNode *res = solu.invertTree(root);
    // show the binary tree level by level
    if(!res) return 0;
    queue<TreeNode *> qt;
    qt.push(res);
    int qtsiz = 1;
    int cnt = 0;
    while(qtsiz > 0)
    {
        ++cnt;
        cout << "level " << cnt << ": ";
        for(int i = 0; i < qtsiz; ++i)
        {
            TreeNode *tmp = qt.front();  qt.pop();
            cout << tmp->val << " ";
            if(tmp->left) qt.push(tmp->left);
            if(tmp->right) qt.push(tmp->right);
        }
        cout << endl;
        qtsiz = qt.size();
    } 
    return 0;
}
