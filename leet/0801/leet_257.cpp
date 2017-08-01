// binary tree path: return all root-to-leaf paths of a given binary tree
#include <iostream>
#include <string>
#include <vector>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        helper(root, res, to_string(root->val));
        return res;
    }
    void helper(TreeNode *root, vector<string>& res, string prev)
    {
        //if(!root) return; // not necessary
        if(!root->left && !root->right) 
        {
            res.push_back(prev);
        }
        if(root->left) helper(root->left, res, prev + "->" + to_string(root->left->val));
        if(root->right) helper(root->right, res, prev + "->" + to_string(root->right->val));
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    Solution solu;
    vector<string> res = solu.binaryTreePaths(root);
    for(int i = 0; i < res.size(); ++i) cout << res[i] << endl;
    return 0;
}
