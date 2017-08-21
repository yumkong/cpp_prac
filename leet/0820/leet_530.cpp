// minimum absolute different in BST
// given a binary search tree with non-negative values, find the minimum absolute difference of any two nodes
// NOTE: there at least two nodes in this BST
#include <iostream>
#include <climits> // INT_MAX, INT_MIN
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
    int getMinimumDifference(TreeNode* root) {
        //do a preorder traverse
        vector<int> arr; 
        helper(root, arr);
        int res = INT_MAX;
        //cout << "0 :" << arr[0] << endl;
        for(int i = 1; i < arr.size(); ++i)
        {
            //cout << i << ": " << arr[i] << endl;
            res = min(res, arr[i] - arr[i-1]);
        }
        return res;
    }
    void helper(TreeNode* root, vector<int>& arr)
    {
        if(!root) return;
        if(root->left) helper(root->left, arr);
        arr.push_back(root->val);
        if(root->right) helper(root->right, arr);
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    cout << solu.getMinimumDifference(root) << endl;
    return 0;
}
