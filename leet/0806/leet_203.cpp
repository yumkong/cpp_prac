// remove all elements with value val from a linked list
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val) head = head->next;
        if(!head) return head; // empty list
        ListNode *prev = head, *cur = head->next;
        while(cur) 
        {
            if(cur->val == val) prev->next = cur->next;
            else prev = cur;
            cur = cur->next;
        }
        return head;
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
    Solution solu;
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(6);
    h1->next->next->next = new ListNode(3);
    h1->next->next->next->next = new ListNode(4);
    h1->next->next->next->next->next = new ListNode(5);
    h1->next->next->next->next->next->next = new ListNode(6);
    
    ListNode *res = solu.removeElements(h1, 6);
    solu.printList(res);
    return 0;
}
