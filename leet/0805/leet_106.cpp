// given inorder and posterorder traversal of a binary tree, construst this tree
// ASSUME duplicates do not exist in the tree
#include <iostream>
#include <vector>
#include <map>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len1 = inorder.size(), len2 = postorder.size();
        if(len1 == 0 || len1 != len2) return NULL;
        // use a map to record the index of root in the inorder array
        map<int, int> mp;
        for(int i = 0; i < len1; ++i) mp[inorder[i]] = i;
        return helper(inorder, 0, len1 - 1, postorder, 0, len1 -1, mp);
    }
    TreeNode *helper(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int, int>& mp)
    {
        if(ps > pe || is > ie) return NULL;
        TreeNode *root = new TreeNode(postorder[pe]); // last node of postorder is the tree root
        int ri = mp[postorder[pe]]; // root pos in the inorder array
        // even in postorder, the left child is the same lenght as the left child of inorder
        // length = start - end + 1 = (ri - 1) - is + 1 = ri - is;
        // so pe = ps + length - 1 = ps + ri - is - 1
        TreeNode *lchild = helper(inorder, is, ri - 1, postorder, ps, ps + ri - is - 1, mp);
        TreeNode *rchild = helper(inorder, ri + 1, ie, postorder, ps + ri - is, pe - 1, mp);
        root->left = lchild;
        root->right = rchild;
        return root;
    }
};

int main()
{
    //TreeNode *root = new TreeNode(1);
    //root->left = new TreeNode(2);
    //root->right = new TreeNode(3);
    //root->left->left = new TreeNode(4);
    //root->left->right = new TreeNode(5);
    vector<int> inorder({4,2,5,1,3});
    vector<int> postorder({4,5,2,3,1});
    Solution solu;
    TreeNode *res = solu.buildTree(inorder, postorder);
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
