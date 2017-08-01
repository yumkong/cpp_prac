// given a non-empty binary tree, return the average value of the nodes on each level in the form of an array
#include <vector>
#include <iostream>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;
        queue<TreeNode *> qt;
        qt.push(root);
        int qtsiz = 1;
        while(qtsiz > 0)
        {
            double sum = 0;
            for(int i = 0; i < qtsiz; ++i)
            {
                TreeNode *tmp = qt.front();  qt.pop();
                sum += tmp->val;
                if(tmp->left) qt.push(tmp->left);
                if(tmp->right) qt.push(tmp->right);
            }
            res.push_back(sum / (double)qtsiz);
            qtsiz = qt.size();
        } 
        return res;
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<double> res = solu.averageOfLevels(root);
    for(int i = 0; i < res.size(); ++i)
    {
        cout << "level " << i+1 << ": " << res[i] << endl;
    }
    return 0;
}
