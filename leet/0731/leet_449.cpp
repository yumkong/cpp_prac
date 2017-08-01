//serialize and deserialize BST
//Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
// hula! all by myself!!!
#include <string> // to_string, stoi
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        if(!root->left && !root->right) return to_string(root->val);
        else return to_string(root->val) + "(" + serialize(root->left) + ")(" + serialize(root->right) + ")";  
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        TreeNode *root = NULL;
        if(data.size() == 1 && data == "#") return root;
        // the idx of first occurance of "("
        int i;
        for(i = 1; i < data.size() && data[i] != '('; ++i);
        int val = stoi(data.substr(0, i));
        root = new TreeNode(val);
        if(i == data.size()) return root;
        else
        {
            stack<char> st;
            st.push('(');
            int j, pos2;
            for(j = i+1; j < data.size(); ++j)
            {
                 if(data[j] == '(') 
                 {
                     st.push('(');
                 }
                 else if(data[j] == ')')
                 {
                     if(st.size() > 0) st.pop();
                     if(st.size() == 0) 
                     { pos2 = j;  break; }
                 }
            }
            root->left = deserialize(data.substr(i+1, pos2 - i - 1));
            // from pos2+2 to data.size()-2 (the 2nd last elem, because the last is ')')
            root->right = deserialize(data.substr(pos2 + 2, data.size() - pos2 - 3));
        }
        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    Codec codec;
    TreeNode *res = codec.deserialize(codec.serialize(root));
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
