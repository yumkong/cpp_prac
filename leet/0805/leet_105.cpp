// given preorder and inorder traversal of a binary tree, construct it
// ASSUME: duplicates do not exist in the tree
#include <iostream>
#include <vector>
#include <map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prelen = preorder.size(), inlen = inorder.size();
        if(prelen == 0 || prelen != inlen) return NULL;
        // <inorder node, inorder pos>
        map<int, int> mp;
        for(int i = 0; i < inlen; ++i) mp[inorder[i]] = i;
        TreeNode *root = helper(preorder, 0, prelen-1, inorder, 0, inlen-1, mp);
        return root;
    }
    TreeNode *helper(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, map<int, int>& mp)
    {
        if(ps > pe || is > ie) return NULL;
        // get root position: the 1st elem of preorder is the root
        int mid = mp[preorder[ps]]; 
        TreeNode *root = new TreeNode(preorder[ps]);
        TreeNode *lchild = helper(preorder, ps + 1, ps + mid - is, inorder, is, mid-1, mp);
        TreeNode *rchild = helper(preorder, ps+mid-is + 1, pe, inorder, mid+1, ie, mp);
        root->left = lchild;
        root->right = rchild;
        return root;
    }
};

int main()
{
    vector<int> inorder({4,2,5,1,3});
    vector<int> preorder({1,2,4,5,3});
    Solution solu;
    TreeNode *res = solu.buildTree(preorder, inorder);
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
