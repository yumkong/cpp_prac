// add two link list, the most significant digit comes at head of list
#include <stack>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        stack<int> st1, st2;
        ListNode* tmp = l1;
        while(tmp) {st1.push(tmp->val); tmp = tmp->next; }
        tmp = l2;
        while(tmp) {st2.push(tmp->val); tmp = tmp->next; }
        ListNode *res = NULL;
        int sum = 0, advance = 0;
        while(!st1.empty() && !st2.empty())
        {
            sum = st1.top() + st2.top() + advance;  st1.pop(); st2.pop();
            advance = sum / 10;
            sum %= 10;
            ListNode *tmp = new ListNode(sum);
            tmp->next = res;  res = tmp;
        }
        while(!st1.empty())
        {
            sum = st1.top() + advance;  st1.pop();
            advance = sum / 10;
            sum %= 10;
            ListNode *tmp = new ListNode(sum);
            tmp->next = res;  res = tmp;
        }
        while(!st2.empty())
        {
            sum = st2.top() + advance;  st2.pop(); 
            advance = sum / 10;
            sum %= 10;
            ListNode *tmp = new ListNode(sum);
            tmp->next = res;  res = tmp;
        }
        if(advance == 1) 
        {
            ListNode *tmp = new ListNode(1);
            tmp->next = res;  res = tmp;
        }
        return res;
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

    ListNode *h2 = new ListNode(5);
    h2->next = new ListNode(6);
    h2->next->next = new ListNode(4);
 
    Solution solu;
    ListNode* res = solu.addTwoNumbers(h1, h2);
    solu.printList(res);
    return 0;
}
