// given a complete binary tree, count the number of nodes
#include <iostream>
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int level = 1;
        vector<int> levelnum(1, 0);
        helper(root, level, levelnum);
        int res = 0;
        for(int i = 0; i < levelnum.size(); ++i) res += levelnum[i];
        return res;
    }
    void helper(TreeNode *root, int level, vector<int>& lev)
    {
        if(!root) return;
        if(level <= lev.size()) ++lev[level - 1];
        else if(level == lev.size() + 1) lev.push_back(1); //the first node in a new level 
        helper(root->left, level + 1, lev);
        helper(root->right, level + 1, lev);
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    
    Solution solu;
    cout << solu.countNodes(root) << endl;
    return 0;
}
