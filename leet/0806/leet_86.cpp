// given a linked list and a int x, partition list s.t. all nodes less than x come before those greater than or 
// equal to x
// NOTE: should preserve the original order of the nodes in each two partitions
//e.g.: Given 1->4->3->2->5->2 and x = 3 ==> 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode *left = new ListNode(0), *right = new ListNode(0), *it = head, *lit = left, *rit = right;
        while(it) 
        {
            if(it->val < x) {lit->next = it; lit = lit->next;}
            else {rit->next = it; rit = rit->next; }
            it = it->next;
        }
        // this is very important!!!
        rit->next = NULL;
        lit->next = right->next;
        return left->next;
    }
};

int main()
{
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(4);
    h1->next->next = new ListNode(3);
    h1->next->next->next = new ListNode(2); 
    h1->next->next->next->next = new ListNode(5);
    h1->next->next->next->next->next = new ListNode(2);
    
    Solution solu;
    ListNode *res = solu.partition(h1, 3);
    ListNode *tmp = res;
    while(tmp) {cout << tmp->val << " "; tmp = tmp->next; }
    cout << endl;
    return 0;
}
