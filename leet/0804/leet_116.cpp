// given a binary tree, populate each next pointer to point to its next right node
// if there is not next right node, should be set to NULL
#include <iostream>
#include <queue>
using namespace std;

//Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode *> qt;
        qt.push(root);
        int qtsiz = 1;
        int rightval;
        while(qtsiz > 0)
        {
            TreeLinkNode *prev = qt.front(); qt.pop();
            if(prev->left) qt.push(prev->left);
            if(prev->right) qt.push(prev->right);
            for(int i = 1; i < qtsiz; ++i)
            {
                prev->next = qt.front();  qt.pop();
                prev = prev->next;
                if(prev->left) qt.push(prev->left);
                if(prev->right) qt.push(prev->right);
            }
            qtsiz = qt.size();
        } 
    }
};

int main()
{
    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);

    Solution solu;
    solu.connect(root);
    TreeLinkNode *tmp = root, *tmp2 = NULL;
    // NOTE the above print only applies for the above tree
    while(tmp)
    {
        tmp2 = tmp;
        while(tmp2) 
        {
            cout << tmp2->val << " ";
            tmp2 = tmp2->next;
        }
        cout << endl;
        tmp = tmp->left;
    }
    return 0;
}
