//implement an iterator over a binary search tree. It is intialized with the root node of a BST.
// call next() will return the next smallest number in the BST
// next() and hasNext() should run in average O(1) and uses O(h) memory, where  h is the height of tree
#include <iostream>
#include <stack>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }
    
    void pushAll(TreeNode *root)
    {
        while(root)
        {
            st.push(root); 
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!st.empty()); 
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = st.top(); st.pop();
        pushAll(tmp->right);
        return tmp->val;
    }
private:
    stack<TreeNode *> st;
};

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);
    //BSTIterator will be called like this:
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next() << endl;

    return 0;
}
