// find the largest value in each row of a binary tree
#include <vector>
#include <iostream>
#include <queue> // a container adapter
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root) return res;  // an empty vector
        queue<TreeNode *> tq;
        tq.push(root);
        int queuesiz = 1;
        int min_int = (1 << 31);
        while(queuesiz > 0)
        {
            int maxval = min_int; //initialize as min
            for(int i = 0; i < queuesiz; ++i)
            {
                TreeNode *cur = tq.front();  tq.pop();
                maxval = max(cur->val, maxval);
                if(cur->left) tq.push(cur->left);
                if(cur->right) tq.push(cur->right);
            }
            res.push_back(maxval);
            queuesiz = tq.size(); // next level's element num
        }
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution solu;
    vector<int> res = solu.largestValues(root);
    for(int i = 0; i < res.size(); ++i)
    {
        cout << "Level " << i << ": " << res[i] << endl;
    } 
    return 0;
}
