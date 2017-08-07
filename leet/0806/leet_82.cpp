// given a sorted linked list, delete all nodes with duplicate numbers, leaving only distinct numbers 
// e.g.:1->2->3->3->4->4->5 =>  1->2->5
#include <iostream>
#include <map>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        // keep each node value's number
        map<int, int> mp;
        ListNode *tmp = head, *prev = head;
        while(tmp) {++mp[tmp->val]; tmp = tmp->next;}
        tmp = head;
        while(tmp)
        {
            // duplicates
            if(mp[tmp->val] > 1) 
            {
                // the first elem is duplicate
                if(tmp == head) { head = head->next; tmp = head; prev = head; }
                else {prev->next = tmp->next; tmp = tmp->next;}
            }
            else
            {
                prev = tmp;
                tmp = tmp->next;
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
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(1);
    h1->next->next = new ListNode(1);
    h1->next->next->next = new ListNode(3); 
    h1->next->next->next->next = new ListNode(3);
    h1->next->next->next->next->next = new ListNode(5);
    h1->next->next->next->next->next->next = new ListNode(5);
    
    Solution solu;
    ListNode *res = solu.deleteDuplicates(NULL);
    solu.printList(res);
    return 0;
}
