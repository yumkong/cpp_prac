// given a binary tree, find its maximum depth
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode *> tq;
        tq.push(root); 
        int queuesiz = 1;
        int level = 0;
        while(queuesiz > 0)
        {
            ++level;
            for(int i = 0; i < queuesiz; ++i)
            {
                TreeNode* tmp = tq.front(); tq.pop();
                if(tmp->left) tq.push(tmp->left);
                if(tmp->right) tq.push(tmp->right);
            }
            queuesiz = tq.size();
        }
        return level;
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(6);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(2);
    cout << solu.maxDepth(root) << endl;
    return 0;
}
