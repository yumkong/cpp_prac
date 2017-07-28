// given a linked list where elements are sorted in ascending order, convert it to a height balanced BST
#include <iostream>
#include <queue>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *tmp = head;
        vector<int> nums;
        while(tmp)
        {
            nums.push_back(tmp->val);
            tmp = tmp->next;
        }
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
    // create list: 1,2,3 ... 9, 10
    ListNode *head = new ListNode(1);
    ListNode *tmp = head;
    for(int i = 2; i < 11; ++i)
    {
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    Solution solu;
    TreeNode *res = solu.sortedListToBST(head);
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
        qsiz = qt.size();
        //cout << "stack size = " << qsiz << endl;
    }
    return 0;
}
