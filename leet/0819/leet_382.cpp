// category: reservior sampling
// Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
//Follow up: What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?
#include <iostream>
#include <cstdint> // rand()
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *hd;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        hd = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n = 0, res = 0;
        ListNode *tmp = hd;
        while(tmp)
        {
            if(n == 0) { res = tmp->val; ++n; }
            else
            {
                ++n;
                // replace the previous val with prob 1/n
                if(rand() % n == 0) res = tmp->val;
            }
            tmp = tmp->next;
        } 
        return res;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution obj(head);
    for(int i = 0; i < 10; ++i) cout << obj.getRandom() << endl;
    return 0;
}
