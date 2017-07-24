// remove duplicates from sorted link list
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
    ListNode* deleteDuplicates(ListNode* head) {
        // only 0 or 1 element
        if(!head || !(head->next)) return head;
        ListNode *tmp = head->next;
        ListNode *tmp_prev = head;
        int prev = head->val;
        while(tmp)
        {    
            // debug
            //cout << "val = " << tmp->val << endl;
            // duplicates
            if(tmp->val == prev)
            {
                // tmp is already the last element!
                if(!(tmp->next)) 
                {
                    tmp_prev->next = NULL;
                    break;
                }
                else
                {
                    tmp_prev->next = tmp->next;
                    // tmp_prev not change in this case, but tmp shifted to its next
                    tmp = tmp->next;
                }
            } 
            else
            {
                prev = tmp->val;
                // shift to the next node
                tmp_prev = tmp;
                tmp = tmp->next;
            }
        }
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    Solution solu;
    ListNode *res = solu.deleteDuplicates(head);
    ListNode *tmp = res;
    while(tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
    return 0;
}
