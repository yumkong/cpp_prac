// remove duplicated element from unsorted link list without extra buffer
// HERE: I want to establish all helper functions for link list for the convenience of later use

#include <iostream>
#include <vector>
using namespace std;

// NOTE: use this as the standard linklist struct => NOT CHANGE ANY MORE
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteDups(ListNode* head)
    { 
        if(!head) return;
        ListNode *prev = head;
        ListNode *curr = prev->next;
        while(curr)
        {
            ListNode *runner = head;
            while(runner != curr)
            {
                if(runner->val == curr->val)
                {
                    prev->next = curr->next;
                    curr = prev->next;
                    break; // all other dups have already been removed
                }
                runner = runner->next;
            }
            // goes here only when no duplicates from head to curr
            if(runner == curr)
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    ListNode* createLinklist(const vector<int> &arr)
    {
        ListNode *head = NULL;
        int len = arr.size();
        if(len == 0) return head;
        head = new ListNode(arr[0]);
        ListNode *tmp = head;
        for(int i = 1; i < len; ++i)
        {
            tmp->next = new ListNode(arr[i]);
            tmp = tmp->next;
        }
        return head;
    }
    void printList(ListNode *head)
    {
        ListNode *tmp = head;
        while(tmp) {cout << tmp->val << " "; tmp = tmp->next; }
        cout << endl;
    }
    void destroyList(ListNode * (&head))
    {
        ListNode *p = head, *q;
        while(p)
        {
            q = p->next;
            delete p;
            p = q;
        }
        head = NULL;
    }
};

int main()
{
    int a[] = {33, 2, 4, 66, 33, 7, 8, 66, 33, 66, 33, 66, 66, 66, 66, 0, 87, 66, 33, 12};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    ListNode *head = solu.createLinklist(arr);
    cout << "Before: "; solu.printList(head);
    solu.deleteDups(head);
    cout << "After: "; solu.printList(head);   

    solu.destroyList(head); 
    return 0;
}
