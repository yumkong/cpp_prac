// given a binary tree, return the tilt of the whole tree
// the tilt of a node is defined as the absolute difference between the sum of all left subtree and
// that of all right subtree
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
    int findTilt(TreeNode* root) {
        int tmp = 0;
        return helper(root, tmp);
    }
    int helper(TreeNode* root, int& sum)
    {
         if(!root) return 0;
         //need to intialize them in case they are not assigned in the next recursion (aka "!root" established)
	 int left = 0, right = 0;
         int tmp = helper(root->left, left) + helper(root->right, right);
         sum = left + right + root->val;
         return tmp + abs(left - right);
    }
private:
    int abs(int a)
    {
        return a >= 0? a:(-a);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution solu;
    cout << solu.findTilt(root) << endl;
    return 0;
}
