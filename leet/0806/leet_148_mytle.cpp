// sort a linked list in O(nlogn) time using constant space complexity
#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return head; // 0 node
        if(!head->next) return head; // 1 node
        int mid = head->val;
        ListNode* left = NULL, *lp = NULL, *right = NULL, *rp = NULL, *it = head->next;
        while(it) 
        {
            if(it->val <= mid)
            {
                if(!left) {left = it; lp = left;}
                else {lp->next = it; lp = lp->next; }
            }
            else
            {
                if(!right) {right = it; rp = right;}
                else {rp->next = it; rp = rp->next; }
            }
            it = it->next;
        }
        // this is very important!!! if check is also important!!!
        if(lp) lp->next = NULL;
        if(rp) rp->next = NULL;

        left = sortList(left);
        right = sortList(right);
        head->next = right;
        if(!left) return head;
        else
        { 
            lp = left;
            while(lp->next) lp = lp->next;
            lp->next = head;
            return left;
        }
    }
    void printList(ListNode *head)
    {
        ListNode *tmp = head;
        while(tmp) {cout << tmp->val << " "; tmp = tmp->next; }
        cout << endl;
    }
};

int main()
{
    ListNode *h1 = new ListNode(2);
    h1->next = new ListNode(1);
    //h1->next->next = new ListNode(4);
    //h1->next->next->next = new ListNode(3);

    Solution solu;
    ListNode *res = solu.sortList(h1);
    solu.printList(res);
    return 0;
}
