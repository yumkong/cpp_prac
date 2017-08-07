// given a linked list, swap every two adjcent nodes and return its head
// should only use constant space, not modify the values in the list, only nodes itself can be changed
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head; // 0 or 1 node
        ListNode *last = NULL, *prev_last = NULL;
        ListNode *newhead = reverseList(head, last, 2);
        prev_last = last;
        while(head && head->next)
        {   // head will automatically updated
            prev_last->next = reverseList(head, last, 2);
            prev_last = last;
        }
        prev_last->next = head;
        return newhead;
    }
    // return value return the reverse list's head, argu head keep's next starting revsered point
    ListNode* reverseList(ListNode * (&head), ListNode * (&last), int k)
    {
        ListNode *prev = NULL;
        last = head;
        while(k > 0)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
            --k;
        }
        return prev;
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
    ListNode *res = solu.swapPairs(h1);
    ListNode *tmp = res;
    while(tmp) {cout << tmp->val << " "; tmp = tmp->next; }
    cout << endl;
    return 0;
}
