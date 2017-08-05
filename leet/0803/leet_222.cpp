// given a complete binary tree, count the number of nodes
#include <iostream>
#include <vector>
#include <cmath>
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int level = 1;
        TreeNode* tmp = root;
        while(tmp->left)
        {
            ++level;
            tmp = tmp->left;
        }
        //if only 1 node
        if(level == 1) return 1;
        int num = 0;
        bool found = false;
        helper(root, 1, level - 1, num, found);
        return (int)(num + pow(2, level - 1) - 1);
    }
    void helper(TreeNode *root, int level, int lastlevel, int &num, bool &found)
    {
        if(!root) return;
        if(found) return;
        if(level == lastlevel)
        {
            if(root->left) ++num;
            else
            { 
                found = true;
                return;
            }
            if(root->right) ++num;
            else
            {
                found = true;
                return;
            }
        }
        else
        {
            helper(root->left, level + 1, lastlevel, num, found);
            helper(root->right, level + 1, lastlevel, num, found);
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    
    Solution solu;
    cout << solu.countNodes(root) << endl;
    return 0;
}
