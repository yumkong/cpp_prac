// given a singly linked list [l0, l1, .., l_n-1, l_n], reorder it to [l0, l_n, l1, l_n-1, l2, ...]
// NOTE: must do it in-place without altering the nodes' values
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
    void reorderList(ListNode* head) {
        // contain 0, 1 or 2 nodes, return itself
        if(!head || !head->next || !head->next->next) return;
        ListNode *fast = head, *slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        } 
        // reverse the half after middle (if odd, not include middle)
        if(fast) slow = slow->next;
        slow = reverse(slow);
        //printList(slow);
        // reorder
        fast = head;
        while(slow)
        {
            cout << "slow = " << slow->val << ", fast = " << fast->val << endl;
            //cout << "premid = " << premid->val << endl;
            ListNode *slownext = slow->next, *fastnext = fast->next;
            slow->next = fast->next;
            fast->next = slow;
            slow = slownext;
            fast = fastnext;
        }
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        while(head)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
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
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(3);
    h1->next->next->next = new ListNode(4);

    Solution solu;
    solu.reorderList(h1);

//    solu.printList(h1);
    return 0;
}
