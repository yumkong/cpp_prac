// given a binary search tree and a target number, return true if there exist two elements in the BST
// s.t. their sum is equal to the given target
// inspried by Solution: using hashset
#include <iostream>
#include <set>
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
    bool findTarget(TreeNode* root, int k) {
        set<int> si; // set.find() => retrieve an set elem, set.count() => check if an elem exist in set
        return find(root, k, si);
    }
    bool find(TreeNode *root, int k, set<int>& si)
    {
        if(!root) return false;
        // if exist, count > 0
        if(si.count(k - root->val) > 0) return true;
        // add the root val to set 
        si.insert(root->val); 
        // recursively find left and right sub-tree
        return find(root->left, k, si) || find(root->right, k, si);
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    cout << solu.findTarget(root, 28) << endl; //false
    return 0;
}
