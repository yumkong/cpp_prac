// given an sorted array in ascending order, covert it to a height balanced BST
//Definition for a binary tree node.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return NULL;
        TreeNode* res = NULL;
        helper(res, nums, 0, len - 1);
        return res;
    }
    void helper(TreeNode* &res, vector<int> &nums, int start, int end)
    {
        // stop criterion 1
        if(start > end) return;
        int mid = (start + end) / 2;
        res = new TreeNode(nums[mid]);
        // stop criterion 2 (can also not use)
        if(start == end) return; 
        // -> has higher priority than * and * has higer than &
        helper(res->left, nums, start, mid - 1);
        helper(res->right, nums, mid + 1, end);
    }
};

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    //cout << "come1" << endl;
    TreeNode* res = solu.sortedArrayToBST(arr);
    //cout << "come2" << endl;
    if(!res) return -1;
    queue<TreeNode *> qt;
    qt.push(res);
    int qsiz = 1;
    while(qsiz > 0)
    { 
        for(int i = 0; i < qsiz; ++i)
        {
            //cout << "come to " << i << endl;
            TreeNode *tmp = qt.front(); qt.pop();
            //cout << "come3" << endl;
            cout << tmp->val << " ";
            if(tmp->left) qt.push(tmp->left);
            if(tmp->right) qt.push(tmp->right);
        }
        cout << endl;
        cout << endl;
        qsiz = qt.size();
        //cout << "stack size = " << qsiz << endl;
    }
    return 0;
}
