// determine if a given linked list has a cycle in it
// Follow up: can it be done without using extra space ?
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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *tmp = head;
        ListNode *tmp2 = head;
        // NOTE tmp2->next is a premise for tmp2->next->next
        while(tmp->next && tmp2->next && tmp2->next->next) 
        {
            tmp = tmp->next; 
            tmp2 = tmp2->next->next;
            if(tmp == tmp2) return true;
        }
        return false;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = head->next;
    Solution solu;
    cout << solu.hasCycle(head) << endl;
    return 0;
}
