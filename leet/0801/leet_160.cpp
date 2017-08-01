// find the node at which the intersection of two singly linked lists begins
// if no intersection return null
// the two linked lists must return their original structure after the funtion returns
// ASSUME: no cycles anywhere
// should run in O(n) and use O(1) memory
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        while(pa != pb) 
        {
            // if coming to the end (null) pointer points to the other list
            pa = (pa) ? pa->next : headB;
            pb = (pb) ? pb->next : headA;
        }
        return pa; // NULL or intersection point
    }
};

int main()
{
    Solution solu;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(6);

    ListNode *head2 = new ListNode(11);
    head2->next = new ListNode(21);
    head2->next->next = new ListNode(31);
    head2->next->next->next = head->next;
    
    ListNode *res = solu.getIntersectionNode(head, head2);
    cout << res->val << endl; // 2
    
    return 0;
}
