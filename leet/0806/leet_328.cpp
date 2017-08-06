// given a singly linked list, group all odd (1,3,5,...) nodes together followed by the even (2,4,6, ...) nodes
// should run in O(1) space complexity and O(n) time complexity
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head; // 0 node
        if(!head->next) return head; // 1 node
        if(!head->next->next) return head; // 2 nodes
        ListNode *oddhead = head, *oddit = head;
        ListNode *evenhead = head->next, *evenit = head->next;
        ListNode *it = head->next->next; // point to 3rd node
        while(it)
        {
            oddit->next = it;  oddit = oddit->next;
            evenit->next = it->next;  evenit = evenit->next;
            if(!it->next) break;
            else it = it->next->next;
        }
        // final concat
        oddit->next = evenhead;
        return oddhead;
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
    h1->next->next = new ListNode(3);
    h1->next->next->next = new ListNode(4);
    h1->next->next->next->next = new ListNode(5);
    h1->next->next->next->next->next = new ListNode(6);
    ListNode *res = solu.oddEvenList(h1);
    solu.printList(res);
    return 0;
}
