// given an int array nums, return a new int array counts of the same length, where counts[i] is the number of smaller elements to the right of nums[i]
// Solu: every node will maintain (1) "sum" to record the total number on its left bottom side,
//  and (2) "dup" counts the duplication
#include <vector>
#include <iostream>
using namespace std;

class Node {
private:
    Node *left, *right;
    int val, sum, dup;
    friend class Solution;
public:
    Node(int v, int s): val(v), sum(s), dup(1), left(NULL), right(NULL) { }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);
        Node *root = NULL;
        for(int i = len - 1; i >= 0; --i)
        {
            root = insert(nums[i], root, res, i, 0);
        }
        return res;
    }
    Node* insert(int num, Node *root, vector<int>& res, int i, int preSum)
    {
        if(!root)// the 1st element
        {
            root = new Node(num, 0);
            res[i] = preSum;
        }
        else if(root->val == num)
        {
            ++root->dup;
            res[i] = preSum + root->sum;
        }
        else if(root->val > num)
        {
            ++root->sum;
            root->left = insert(num, root->left, res, i, preSum);
        }
        else root->right = insert(num, root->right, res, i, preSum + root->dup + root->sum);
        return root;
    }
};

int main()
{
    Solution solu;
    vector<int> input({5,2,6,1});
    vector<int> res = solu.countSmaller(input);
    for(auto &i: res) cout << i << " ";
    cout << endl;
    return 0;
}
