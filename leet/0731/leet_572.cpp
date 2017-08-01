// given two ***non-empty*** binary trees s and t, check wether t is a subtree of s
#include <string>
#include <iostream>
#include <map>
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        map<string, int> mp; // here vector<string>, set<string> are also ok
        string sub = helper(t);
        //cout << "sub = " << sub << endl;
        finder(s, mp);
        return (mp.count(sub) > 0);
    }
    string helper(TreeNode *root)
    {
        if(!root) return "#";
        return to_string(root->val) + "(" + helper(root->left) + ")(" + helper(root->right) + ")";
    }
    string finder(TreeNode *root, map<string, int> &mp)
    {
        if(!root) return "#";
        string res = to_string(root->val) + "(" + finder(root->left, mp) + ")(" + finder(root->right, mp) + ")";
        ++mp[res];
        //cout << res << endl;
        return res;
    }
};

int main()
{
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);

    TreeNode *root2 = new TreeNode(4);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(2);

    Solution solu;
    cout << solu.isSubtree(root1, root2) << endl;
    return 0;
}
