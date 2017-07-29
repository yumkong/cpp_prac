// given a binary tree, flatten it to a linked list ***in-place***
// each node's right child points to the next node of a pre-order traversal
//Definition for a binary tree node.
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        // swap right and left
        TreeNode* tmp = root;
        // while iter, each iter put root's right at the end of root's left' rightmost node
        while(tmp) 
        {
            if(tmp->left)
            {
                TreeNode *prev = tmp->left;
                while(prev->right) prev = prev->right; // prev points to rightmost
                prev->right = tmp->right; // rightmost's right node points to root's right
                // change left as right
                tmp->right = tmp->left;
                tmp->left = NULL;
            }
            tmp = tmp->right;
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    Solution solu;
    solu.flatten(root);
    // print
    TreeNode *tmp = root;
    while(tmp) 
    {
        cout << tmp->val << " ";
        tmp = tmp->right;
    }
    cout << endl;
    return 0;
}
