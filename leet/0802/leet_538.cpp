// given a binary search tree (BST), convert it to a Greater tree s.t. every key of the original BST is changed to the orignal key plus sum of all keys greater than the original key in BST.
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
    TreeNode* convertBST(TreeNode* root) {
        //if(!root) return root;
        int i = 0;
        helper(root, i);
        return root;  
    }
    void helper(TreeNode* root, int &i)
    {
        if(!root) return;
        // avoid going extra depth
        if(root->right) helper(root->right, i);
        root->val += i;
        i = root->val; // update i
        if(root->left) helper(root->left, i);
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(13);

    TreeNode *res = solu.convertBST(root);
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
