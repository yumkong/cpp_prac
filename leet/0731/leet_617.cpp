// merge two binary trees
// given two binary trees and merge them: if two nodes overlap sum them
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        helper(t1, t2);
        return t1; // use t1 as destination tree  
    }
    TreeNode* helper(TreeNode *t1, TreeNode *t2)
    {
        if(!t1) return t2;
        if(!t2) return t1;
        t1->val = t1->val + t2->val;
        t1->left = helper(t1->left, t2->left);
        t1->right = helper(t1->right, t2->right);
        return t1;
    }
};

int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(5);
    root1->right = new TreeNode(2);

    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);
    
    Solution solu;
    TreeNode *res = solu.mergeTrees(root1, root2);
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
