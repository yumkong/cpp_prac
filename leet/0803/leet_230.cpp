// given a binary search tree, find kth smallest element
// Further: What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
// ASSUME: k is always valid
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
    int kthSmallest(TreeNode* root, int k) {
        int index = 0;
        bool found = false;
        return helper(root, index, k, found);
    }
    int helper(TreeNode *root, int &index, int k, bool &found)
    {
        if(!root) return 0;
        // left
        int left = helper(root->left, index, k, found);
        if(found) return left; 
        // mid
        ++index;
        //cout << "index = " << index << ", rootval = " << root->val << endl;
        if(index == k) 
        {
            found = true;
            return root->val;
        }
        // right
        int right = helper(root->right, index, k, found);
        if(found) return right;
        return 0;
    }
};

int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    
    Solution solu;
    cout << solu.kthSmallest(root, 6) << endl; 
    return 0;
}
