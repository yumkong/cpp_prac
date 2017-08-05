// given a binary tree return the right side view from top to bottom
#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode *> qt;
        qt.push(root);
        int qtsiz = 1;
        int rightval;
        //int cnt = 0;
        while(qtsiz > 0)
        {
        //++cnt;
        //cout << "level " << cnt << ": ";
            for(int i = 0; i < qtsiz; ++i)
            {
                TreeNode *tmp = qt.front();  qt.pop();
                rightval = tmp->val;
                if(tmp->left) qt.push(tmp->left);
                if(tmp->right) qt.push(tmp->right);
            }
            res.push_back(rightval);
            //cout << endl;
            qtsiz = qt.size();
        } 
        return res;
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right-> right = new TreeNode(4);
    vector<int> res = solu.rightSideView(root);
    for(auto &i: res) cout << i << endl;
    return 0;
}
