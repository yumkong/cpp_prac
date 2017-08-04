// given a binary tree each node represent the money, but cannot get the money from directly linked node (aka. father-left or father-right), find the way to get the maximum amount of money
#include <queue>
#include <iostream>
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
    int rob(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode *> qt;
        qt.push(root);
        int qtsiz = 1;
        int cnt = 0;
        vector<int> levelsum;
        while(qtsiz > 0)
        {
            int sum = 0;
            for(int i = 0; i < qtsiz; ++i)
            {
                TreeNode *tmp = qt.front();  qt.pop();
                sum += tmp->val;
                if(tmp->left) qt.push(tmp->left);
                if(tmp->right) qt.push(tmp->right);
            }
            levelsum.push_back(sum);
            qtsiz = qt.size(); // update qtsiz
        }
        // begin a dp
        int len = levelsum.size();
        vector<int> dp(len, 0);
        dp[0] = levelsum[0];
        dp[1] = max(levelsum[0], levelsum[1]);
        for(int i = 2; i < len; ++i)
        {
            dp[i] = max(dp[i - 1], levelsum[i] + dp[i - 2]); 
        }   
        return dp[len - 1];
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << solu.rob(root) << endl;
    return 0;
}
