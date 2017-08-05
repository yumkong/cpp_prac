// given a binary tree containing digits from 0-9 only, each root-to-leaf path can represent a number
// find the total sum of all root-to-leaf numbers
#include <iostream>
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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        int sum = 0;
        helper(root, res, sum);
        return sum;
    }
    void helper(TreeNode *root, int res, int &sum)
    {
        if(!root) return;
        res = res * 10 + root->val;
        if(!root->left && !root->right) 
        {
            sum += res;
            return;
        }
        else
        {
            if(root->left) helper(root->left, res, sum);
            if(root->right) helper(root->right, res, sum);
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution solu;
    cout << solu.sumNumbers(root) << endl;
    return 0;
}
