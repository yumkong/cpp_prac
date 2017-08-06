// given int n, generate all structurally unique BST that store values 1,2,...,n
// 1,2, .., n is the inorder traversal, then we can recursively call to get back all possible
// left and right subtrees and combine them with the root
#include <vector>
#include <iostream>
#include <queue>
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
    vector<TreeNode*> generateTrees(int n) {
        // can use a vector<TreeNode *> dp
        vector<TreeNode *> res;
        if(n == 0) return res;
        return helper(1, n);
    }
    vector<TreeNode *> helper(int start, int end)
    {
        vector<TreeNode *> res;
        // note the following is wrong (the vector cannot be empty!!!)
        //if(start > end) return res;
        if(start > end) {res.push_back(NULL); return res; }
        if(start == end) {res.push_back(new TreeNode(start)); return res;};
        vector<TreeNode *> left, right;
        for(int i = start; i <= end; ++i)
        {
            left = helper(start, i - 1);
            right = helper(i + 1, end);
            for(auto& lnode: left)
            {
                for(auto& rnode: right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<TreeNode *> resall = solu.generateTrees(3);
    // show the binary tree level by level
    for(int k = 0; k < resall.size(); ++k)
    {
        TreeNode *res = resall[k];
        cout << "Tree " << k << ":" << endl; 
        if(!res) return 0;
        queue<TreeNode *> qt;
        qt.push(res);
        int qtsiz = 1;
        int cnt = 0;
        while(qtsiz > 0)
        {
            ++cnt;
            cout << "level " << cnt << ": ";
            for(int i = 0; i < qtsiz; ++i)
            {
                TreeNode *tmp = qt.front();  qt.pop();
                cout << tmp->val << " ";
                if(tmp->left) qt.push(tmp->left);
                if(tmp->right) qt.push(tmp->right);
            }
            cout << endl;
            qtsiz = qt.size();
        }
        cout << endl;
    } 
    return 0;
}
