// given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum
#include <iostream>
#include <vector>
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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        if(!root) return res; // empty vvi
        vector<int> elem;  //elem.push_back(root->val); // root's val as first elem
        helper(root, sum, 0, res, elem);
        return res;
    }
    void helper(TreeNode* root, int sum, int cur, vector<vector<int> > &res, vector<int> &elem)
    {
        // NOTE root is always not NULL
        cur += root->val;
        elem.push_back(root->val);
        // if root is leaf
        //cout << "cur = " << cur << endl;
        if(!root->left && !root->right && cur == sum) res.push_back(elem);
        else
        { 
            if(root->left) helper(root->left, sum, cur, res, elem);
            if(root->right) helper(root->right, sum, cur, res, elem);
        }
        // finally release the val added at the begining
        cur -= root->val;
        elem.pop_back();
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    Solution solu;
    vector<vector<int> > res = solu.pathSum(root, 22);
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
