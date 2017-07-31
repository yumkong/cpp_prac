// the left subtree of a node => keys less than the node's key
// the right subtree of a node => keys greater than the node's key
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
    bool isValidBST(TreeNode* root) {
        //if(!root) return true;
        return dfs(root, NULL, NULL);
    }
    bool dfs(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
    {
        if(!root) return true;
        // if dfs-ing in the middle and condition not satisfied, quit by returning false
        if((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
        {
            return false;
        }
        // recursion
        return dfs(root->left, minNode, root) && dfs(root->right, root, maxNode);
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(20);
    cout << solu.isValidBST(root) << endl;
    return 0;
}
