// given a binary tree, return the level order travesal of its nodes' values 
#include <iostream>
#include <vector>
#include <queue>
//#include <algorithm> //std::reverse
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        queue<TreeNode *> qt;
        qt.push(root);
        int qtsiz = 1;
        //int revflag = false;
        while(qtsiz > 0)
        {
            vector<int> tmpvec;
            for(int i = 0; i < qtsiz; ++i)
            {
                TreeNode *tmp = qt.front();  qt.pop();
                tmpvec.push_back(tmp->val);
                if(tmp->left) qt.push(tmp->left);
                if(tmp->right) qt.push(tmp->right);
            }
            //if(revflag) reverse(tmpvec.begin(), tmpvec.end());
            res.push_back(tmpvec);
            //revflag = !revflag;
            qtsiz = qt.size();
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
    vector<vector<int> > res = solu.zigzagLevelOrder(root);
    for(auto &i: res)
    {
        for(auto &k: i) cout << k << " ";
        cout << endl;
    }
    return 0;
}
