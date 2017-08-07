//given a linked list, return the node where the cycle begins
// NOTE: do not modify the linked list
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
    ListNode *detectCycle(ListNode *head) {
		if(!head || !head->next) return NULL; // only 0 or 1 node
        ListNode *fast = head, *slow = head;
		while(fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if(fast == slow) break;
		}
		// no cycle
		if(fast != slow) return NULL;
		fast = head;
		while(fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
    }
};

int main()
{
	ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(3);
    h1->next->next->next = new ListNode(4);
	h1->next->next->next->next = h1->next;

    Solution solu;
    ListNode *res = solu.detectCycle(h1);
	cout << res->val << endl;
	return 0;
}