// given a binary tree return all duplicate subtrees (have the same structure with same node value)
// return the root node of any one of the subtrees
// NOTE: tree is the place where recursion is in good use
// CORE: find a dictionary to represent each sub-tree
#include <vector>
#include <iostream>
#include <map>
#include <string> //std::to_string(int)
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        if(!root) return res;
        map<string, int> mp;
        postorder(root, mp, res);
        return res;
    }
    string postorder(TreeNode *root, map<string, int> &mp, vector<TreeNode*> &res)
    {
        if(!root) return "#";
        string serial = to_string(root->val) + "," + postorder(root->left, mp, res) + 
                                               "," + postorder(root->right, mp, res);
        ++mp[serial];
        // only add the duplication once
        if(mp[serial] == 2) res.push_back(root);
        return serial;
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);
    vector<TreeNode *> res = solu.findDuplicateSubtrees(root);
    for(auto& tp: res) cout << tp->val << endl;
    return 0;
}


