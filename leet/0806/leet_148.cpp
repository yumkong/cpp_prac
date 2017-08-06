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
        if(!head || !head->next) return head; // 0 or 1 node
        // geometrically cut the list to two halves
        ListNode* prev = NULL, *slow = head, *fast = head;
        while(fast && fast->next) 
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // this is crucial for cutting into two halves
        prev->next = NULL;
     
        // sort the two halves
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        // finally merge
        return merge(left, right);
    }
    ListNode* merge(ListNode *l1, ListNode *l2)
    {
        // given an artificial head first, to avoid unnessary comparison in while loop
        // then return head->next
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while(l1 && l2)
        {
            if(l1->val < l2->val) {p->next = l1; l1 = l1->next; }
            else {p->next = l2; l2 = l2->next; }
            p = p->next;
        }
        if(l1) p->next = l1;
        if(l2) p->next = l2;
        return head->next;
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
