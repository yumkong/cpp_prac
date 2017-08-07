// given a linked list, remove the ith node from the end of list and return resulting list's head
// NOTE: n is always valid, try to do it on one pass
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || n == 0) return head;
        //if(!head->next || n == 1) return NULL; // 1 node and n = 1 
        ListNode* tmp = head, *prev = head;
        for(int i = 0; i < n; ++i) tmp = tmp->next;
        // the first elem to be deleted
        if(!tmp) head = head->next;
        else
        {   cout << "come2" << endl;
            while(tmp && tmp->next) {prev = prev->next; tmp = tmp->next; }
            // NOTE prev->next is to be deleted, which is always valid
            tmp = prev->next->next;
            prev->next = tmp;
        }
        return head;
    }
};

int main()
{
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(2);
    //h1->next->next = new ListNode(3);
    //h1->next->next->next = new ListNode(4);
    //h1->next->next->next->next = new ListNode(5);
    Solution solu;
    ListNode *res = solu.removeNthFromEnd(h1, 1);
    ListNode *tmp = res;
    while(tmp) {cout << tmp->val << " "; tmp = tmp->next; }
    cout << endl;
    return 0;
}
