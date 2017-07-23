// two elements of a binary search tree (BST) are swapped by mistake
// recover the tree without changing its structure
// devise a constant space solution
#include <iostream>
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
    void recoverTree(TreeNode* root) {
        int min_int = (1 << 31);
        firstElm = NULL;
        secondElm = NULL;
        prevElm = new TreeNode(min_int);
        // in-order (zhongxu) traversal to find the two elements
        traverseFind(root);
        // swap
        int tmp = firstElm->val;
        firstElm->val = secondElm->val;
        secondElm->val = tmp;
    }
    void traverseFind(TreeNode* root)
    {
        if(!root) return;
        traverseFind(root->left);
        // ### start ###
        // first time bigger element is wrong
        if(!firstElm && prevElm->val >= root->val) firstElm = prevElm;
        // second time smaller element is wrong
        if(firstElm && prevElm->val >= root->val) secondElm = root;
        prevElm = root;
        // ### end ###
        traverseFind(root->right);
    }
    void traversePrint(TreeNode* root)
    {
        if(!root) return;
        traversePrint(root->left);
        cout << root->val << " ";
        traversePrint(root->right); 
    }
    // put initilization at recoverTree func
    //Solution()
    //{
    //    firstElm = NULL;
    //    secondElm = NULL;
    //    preElm = NULL;
    //}
private:
    TreeNode* firstElm;
    TreeNode* secondElm;
    TreeNode* prevElm; // the preceeding element
};

int main()
{
    Solution solu;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(6);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(2);
    //print before
    cout << "before: ";
    solu.traversePrint(root);
    cout << endl;
    // do the swapping
    solu.recoverTree(root);
    // print after
    cout << "after: ";
    solu.traversePrint(root);
    cout << endl;
    return 0;
}
