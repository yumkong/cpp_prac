// delete node in a BST(binary search tree)
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        // root is the key
        if(root->val == key)
        {
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            TreeNode *pt = root->left;
            while(pt->right) pt = pt->right;
            pt->right = root->right;
            // use root->left as the new root and put root->right at the rightmost subtree
            return root->left;
        }
        TreeNode *tmp = root;
        TreeNode *prev = root;
        while(tmp) 
        {
            if(tmp->val == key) break;
            else
            {
                prev = tmp;
                if(tmp->val > key) tmp = tmp->left;
                else tmp = tmp->right;
            }
        }
        //cout << "come1: tmp->val = " << tmp->val << endl;
        //cout << "come2: prev->val = " << prev->val << endl; 
        //if key not found, return original root
        if(!tmp || tmp->val != key) return root;
        else 
        {
            // a leaf node
            if(!tmp->left && !tmp->right)
            {
                 if(prev->val < tmp->val) prev->right = NULL;
                 else prev->left = NULL;
            }
            else if(!tmp->left)
            {
                 if(prev->val < tmp->right->val) prev->right = tmp->right;
                 else prev->left = tmp->right;
            }
            else if(!tmp->right)
            {
                 if(prev->val < tmp->left->val) prev->right = tmp->left;
                 else prev->left = tmp->left;
            }
            else
            {
                 TreeNode *t = tmp->left;
                 while(t->right) t = t->right;
                 t->right = tmp->right;
                 if(prev->val < tmp->left->val) prev->right = tmp->left;
                 else prev->left = tmp->left;
            }
        }
        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution solu;
    TreeNode *res = solu.deleteNode(root, 3);
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
