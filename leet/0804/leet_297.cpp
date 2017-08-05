// serilize and deserialize a binary tree
// refer to leet_449: serialize and deserialize a BST (binary search tree)
#include <iostream>
#include <string> // c++11: to_string, stoi
#include <queue>
#include <stack>
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
        if(!root) return ""; // root is empty, return empty string
        if(!root->left && !root->right) return to_string(root->val);
        // if right child is missing root(left) => not need the 2nd braces
        if(!root->right) return to_string(root->val) + "(" + serialize(root->left) + ")"; 
        // otherwise root(left)(right), even if the left child is missing
        return to_string(root->val) + "(" + serialize(root->left) + ")(" + serialize(root->right) + ")";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = NULL;
        if(data.size() == 0) return root;
        int i = 0; // keep the end pos of the root value
        for(i = 1; i < data.size() && data[i] != '('; ++i);
        int val = stoi(data.substr(0, i));
        root = new TreeNode(val);
        // only contain root node, no childs
        if(i == data.size()) return root;
        else
        {
            stack<char> st; 
            st.push('('); // first push the '(' at ith position
            int j, pos2; // pos2 keep the left child's ending position
            for(j = i + 1; j < data.size(); ++j)
            {
                if(data[j] == '(') st.push('(');
                else if(data[j] == ')')
                {
                    if(st.size() > 0) st.pop();
                    if(st.size() == 0) {pos2 = j; break;}
                }
            }
            root->left = deserialize(data.substr(i+1, pos2 - i - 1));
            // check if there is right child
            if(pos2 < data.size() - 1) // from [pos2+2, data.size()-2] // leave out the last ')'
            { root->right = deserialize(data.substr(pos2 + 2, data.size() - pos2 - 3)); }
        }
        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    // Your Codec object will be instantiated and called as such:
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
