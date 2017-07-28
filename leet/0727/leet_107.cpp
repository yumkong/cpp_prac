// given a binary tree the bottom-up traversal of its nodes
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        queue<TreeNode *> qt;
        qt.push(root);
        int qsiz = 1;
        while(qsiz > 0)
        { 
            vector<int> vtmp;
            for(int i = 0; i < qsiz; ++i)
            {
                TreeNode *tmp = qt.front(); qt.pop();
                vtmp.push_back(tmp->val);
                //cout << "push back: " << tmp->val << endl;
                if(tmp->left) qt.push(tmp->left);
                if(tmp->right) qt.push(tmp->right);
            }
            res.insert(res.begin(), vtmp);
            qsiz = qt.size();
            //cout << "stack size = " << qsiz << endl;
        }
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution solu;
    vector<vector<int> > res = solu.levelOrderBottom(root);
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
