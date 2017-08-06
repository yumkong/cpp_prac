// sort a linked list using insertion sort
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head; // 0 or 1 node
        ListNode *prev = head, *it = head->next, *tmp = NULL, *tmp_prev;
        while(it)
        {
            if(head->val > it->val)
            {
                prev->next = it->next;
                it->next = head;
                head = it;
                it = prev->next;
                continue;
            }
            else
            {
                tmp_prev = head;
                tmp = head->next;
                while(tmp != it && tmp->val <= it->val) {tmp_prev = tmp; tmp = tmp->next;}
                if(tmp != it) 
                {
                    prev->next = it->next;
                    it->next = tmp;
                    tmp_prev->next = it;
                    it = prev->next;
                }
                else // no need to swap, move to next node
                {
                    prev = it;
                    it = it->next;
                }
            }
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
    ListNode *h1 = new ListNode(7);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(4);
    h1->next->next->next = new ListNode(3);

    Solution solu;
    ListNode* res = solu.insertionSortList(h1);
    solu.printList(res);
    return 0;
}
