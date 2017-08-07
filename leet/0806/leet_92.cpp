// reverse a linked list from position m to n, in-place and in-one-pass
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m >= n) return head;
        ListNode *prev = NULL, *start = head, *it = head;
        // let it point to m
        for(int i = 1; i < m; ++i) {start = it; it = it->next; }
        ListNode *end = start->next;
        for(int i = m; i <= n; ++i)
        {
            ListNode *next = it->next;
            //cout << next->val << endl;
            it->next = prev;
            // at the last iteration, point to the normal next
            //if(i == n - 1) it->next = next;
            prev = it;
            it = next;
        }
        // if reversing from beginning, start is the last element of reversed sub-list
        if(m == 1)
        {
            start->next = it;
            head = prev;
        }
        else
        {
            start->next = prev; // prev is the start of reverse
            end->next = it;
        }
        return head;
    }
};

int main()
{
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(3);
    //h1->next->next->next = new ListNode(4);
    //h1->next->next->next->next = new ListNode(5);
    Solution solu;
    ListNode *res = solu.reverseBetween(h1, 2, 3);
    ListNode *tmp = res;
    while(tmp) {cout << tmp->val << " "; tmp = tmp->next; }
    cout << endl;
    return 0;
}
