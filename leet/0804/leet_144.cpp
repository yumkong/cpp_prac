// binary tree preorder traversal
// NOTE: recursive solution is trivial, can you do it iteratively?
#include <vector>
//#include <deque>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        //helper_recursive(root, res);
        helper_iterative(root, res);
        return res;
    }
    void helper_iterative(TreeNode *root, vector<int> &res)
    {
        if(!root) return;
        TreeNode *p = root;
        stack<TreeNode *> st;
        while(p || !st.empty())
        {
            if(p)
            {
                st.push(p);
                // add at end of res
                res.push_back(p->val);
                p = p->left;
            }
            else
            {
                TreeNode *tmp = st.top(); st.pop();
                p = tmp->right;
            }
        }
    }

    void helper_recursive(TreeNode *root, vector<int> &res)
    {
        if(!root) return;
        res.push_back(root->val);
        helper_recursive(root->left, res);
        helper_recursive(root->right, res);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(66);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    Solution solu;
    vector<int> res = solu.preorderTraversal(root);
    for(auto &i: res) cout << i << " ";
    cout << endl;
    return 0;
}
