// given a binary tree, find the leftmost value in the last row of the tree
// premise: the tree (root) is not NULL
#include <vector>
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> tq;
        tq.push(root);
        int queuesiz = 1;
        int res;
        while(queuesiz > 0)
        {
            // get the leftmost value of each layer
            res = tq.front()->val;
            for(int i = 0; i < queuesiz; ++i)
            {
                TreeNode *tmp = tq.front();  tq.pop();
                // push its child to the end of the queue
                if(tmp->left) tq.push(tmp->left);
                if(tmp->right) tq.push(tmp->right);
            }
            // update queuesize: the total num of the next level
            queuesiz = tq.size();
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
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);

    cout << solu.findBottomLeftValue(root) << endl;
    return 0;
}
