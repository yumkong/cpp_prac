// construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way
#include <string>
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
    string tree2str(TreeNode* t) {
        if(!t) return ""; // empty string
        return helper(t);
    }
    string helper(TreeNode *root)
    {
        if(!root) return "()";
        string res;
        if(root->left && root->right) 
        {
            res = to_string(root->val) + "(" + helper(root->left) + ")(" + helper(root->right) + ")";
        }
        else if(root->left && !root->right) res = to_string(root->val) + "(" + helper(root->left) + ")";
        else if(!root->left && root->right) res = to_string(root->val) + "()(" + helper(root->right) + ")";
        else res = to_string(root->val);
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    Solution solu;
    cout << solu.tree2str(root) << endl;
    return 0;
}
