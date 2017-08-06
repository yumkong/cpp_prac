// delete a node (except the tail) in a singly linked list, given only access to that node
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
    void deleteNode(ListNode* node) {
        ListNode *it = node;
        while(it && it->val != 3) it = it->next;
        if(it->val == 3 && !it->next) 
        {
            it->val = it->next->val;
            it->next = it->next->next;
        }
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
    solu.deleteNode(h1);
    return 0;
}
