// given the root of a binary tree, value v and depth d => add a row of nodes with value v at the given depth d
// the root node is at depth 1
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        //if(!root && d > 1) return NULL; // this addition cannot be achieved
        //if(!root && d == 1) 
        //{
        //    TreeNode *res = new TreeNode(v);
        //    return res;
        //}
        if(d == 1)
        {
            TreeNode *res = new TreeNode(v);
            res->left = root;
            return res;
        }
        queue<TreeNode *> qt;
        qt.push(root);
        int qtsiz = 1;
        int cnt = 1;
        while(qtsiz > 0)
        {
            ++cnt;
            if(cnt == d)
            {
                for(int i = 0; i < qtsiz; ++i)
                {
                    TreeNode *tmp = qt.front();  qt.pop();
                    TreeNode *newleft = new TreeNode(v);
                    TreeNode *newright = new TreeNode(v);
                    if(tmp->left) newleft->left = tmp->left;
                    if(tmp->right) newright->right = tmp->right;
                    tmp->left = newleft;
                    tmp->right = newright;
                }
                break; // quit while
            }
            for(int i = 0; i < qtsiz; ++i)
            {
                TreeNode *tmp = qt.front();  qt.pop();
                if(tmp->left) qt.push(tmp->left);
                if(tmp->right) qt.push(tmp->right);
            }
            qtsiz = qt.size();
        } 
        return root; // in-place addition
    }
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    TreeNode *res = solu.addOneRow(root, 666, 3);
    // show the binary tree level by level
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
    return 0;
}
