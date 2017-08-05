// return the postorder traversal (left, right, root) of its nodes' value
// NOTE: recursive solution is trivial, can you do it iteratively?
#include <vector>
#include <deque>
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
    vector<int> postorderTraversal(TreeNode* root) {
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
        deque<TreeNode *> dq;
        while(p || !dq.empty())
        {
            if(p)
            {
                dq.push_front(p);
                // add at beginning of res
                res.insert(res.begin(), p->val);
                p = p->right;
            }
            else
            {
                TreeNode *tmp = dq.front(); dq.pop_front();
                p = tmp->left;
            }
        }
    }

    void helper_recursive(TreeNode *root, vector<int> &res)
    {
        if(!root) return;
        helper_recursive(root->left, res);
        helper_recursive(root->right, res);
        res.push_back(root->val);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution solu;
    vector<int> res = solu.postorderTraversal(root);
    for(auto &i: res) cout << i << " ";
    cout << endl;
    return 0;
}
