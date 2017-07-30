// given a binary tree find the maximum path sum
// a path is any sequence of nodes from some starting node to any node in the tree along the parent
// -child connections. The path contain at least one node and not need to do through the root
#include <iostream>
#include <climits> //INT_MIN
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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxval = INT_MIN;
        helper(root, maxval);
        return maxval;
    }
    int helper(TreeNode *root, int &maxval)
    {
        if(!root) return 0;
        int left = max(0, helper(root->left, maxval));
        int right = max(0, helper(root->right, maxval));
        maxval = max(maxval, left + right + root->val);
        return max(left, right) + root->val; // return left- or right- half subtree
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution solu;
    cout << solu.maxPathSum(root) << endl;
    return 0;
} 
