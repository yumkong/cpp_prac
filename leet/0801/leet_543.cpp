// compute the length of a binary tree
#include <iostream>
//#include <>
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
    int diameterOfBinaryTree(TreeNode* root) {
        maxlen = 0; // init as 0
        helper(root);
        return maxlen;
    }
    int helper(TreeNode *root)
    {
        if(!root) return -1;
        int left = helper(root->left) + 1;
        int right = helper(root->right) + 1;
        // objective 1: sum for comparing and get final result
        if(left + right > maxlen) maxlen = left + right;
        // objective 2: single-path max val as return value
        return max(left, right);
    }
private:
    int maxlen;
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(6);
    Solution solu;
    cout << solu.diameterOfBinaryTree(root) << endl;
    return 0;
}
