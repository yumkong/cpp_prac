// given a complete binary tree, count the number of nodes
#include <iostream>
#include <vector>
#include <cmath> // pow(x,y) == x ^ y
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
        int hleft = 0, hright = 0;
        TreeNode* l = root, *r = root;
        while(l)
        {
            ++hleft;
            l = l->left;
        }
        while(r)
        {
            ++hright;
            r = r->right;
        }
        if(hleft == hright) return pow(2, hleft) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
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
