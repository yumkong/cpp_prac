// rotate a list to the right by k places, where k is non-negative
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;
        int j = k;
        ListNode *tmp = head, *tmp_prev = NULL;
        ListNode *newhead = head, *prev = NULL;
        while(j > 0 && tmp) {tmp = tmp->next; --j; };
        // what if k is very large (larger than list length) ?
        if(j > 0) 
        {
            int len = k - j;
            k %= len;
            if(k == 0) return head;
            else
            { 
                j = k;
                tmp = head, prev = NULL;
                while(j > 0 && tmp) {prev = tmp; tmp = tmp->next; --j; };
            }
        }
        if(!tmp) return head; // j = 0 and tmp = NULL
        while(tmp)
        {
            prev = newhead;
            newhead = newhead->next;
            tmp_prev = tmp;
            tmp = tmp->next;
        }
        tmp_prev->next = head;
        prev->next = NULL;
        return newhead;
    }
};

int main()
{
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(3);
    h1->next->next->next = new ListNode(4); 
    h1->next->next->next->next = new ListNode(5);
    Solution solu;
    ListNode *res = solu.rotateRight(h1, 2);
    ListNode *tmp = res;
    int cnt = 10;
    while(tmp && cnt > 0) {cout << tmp->val << " ";  tmp = tmp->next; --cnt;}
    cout << endl;
    return 0;
}
