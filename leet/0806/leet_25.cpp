// given a linked list, reverse the nodes of a list of length k at a time
// k is positive and less that or equal to the length of the linked list
// if list length is not a multiple of k,  the left-out nodes in the end should remain as it is.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1) return head;// 0 or 1 nodes or k==1
        // get list length
        int len = 0;
        ListNode* tmp = head;
        while(tmp) { ++len; tmp = tmp->next; };
        // important!!!
        if(len < k) return head;
        int reverse_cnt = len / k;
        ListNode *last = NULL, *prev_last = NULL;
        ListNode *newhead = reverseList(head, last, k); --reverse_cnt;
        prev_last = last;
        while(reverse_cnt > 0)
        {   // head will automatically updated
            prev_last->next = reverseList(head, last, k);
            prev_last = last;
            --reverse_cnt;
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
    ListNode *res = solu.reverseKGroup(h1, 3);
    ListNode *tmp = res;
    while(tmp) {cout << tmp->val << " "; tmp = tmp->next; }
    cout << endl;
    return 0;
}
