// determine whether a singly linked list is a palindrome
// do it in O(n) time and O(1) space
// SOLU: reverse the 2nd half and compare the two halves
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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        // given fast, slow will never across the border
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // odd nodes, make right half smaller
        if(fast) slow = slow->next;
        slow = reverse(slow); // reverse from [slow, end]
        fast = head;
        while(slow)
        {
            if(fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        while(head)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

int main()
{
    Solution solu;
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(3);
    h1->next->next = new ListNode(3);
    h1->next->next->next = new ListNode(1);
    cout << solu.isPalindrome(h1) << endl;
    return 0;
}
