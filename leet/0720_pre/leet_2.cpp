#include <iostream>
#include <map>
#include <vector>
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
    ListNode* res = NULL, *p, *q, *remainList;
    int carry = 0, sum = 0;
    while(l1 && l2)
    {
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        sum = sum % 10;
        q = new ListNode(sum);
        if(res)
        {
            p->next = q;
        }
        else // res is empty
        { 
            res = q;
        }
        p = q; // p always point to the last elem
        l1 = l1->next;
        l2 = l2->next;
    }
    if(l1) remainList = l1;
    else remainList = l2;
    while(remainList)
    {
        sum = remainList->val + carry;
        carry = sum / 10;
        sum = sum % 10;
        q = new ListNode(sum);
        if(res) p->next = q;
        else res = q;
        p = q;
        remainList = remainList->next;
    }
    if(carry > 0)
    {
        q = new ListNode(1);
        if(res) p->next = q;
        else res = q;
    }
    return res;
  }//end of addTwoNumbers
};

int main()
{
    Solution solu;
    int arr1[] = {1, 2, 3, 4, 9};
    int arr2[] = {1, 3, 8};
    ListNode *l1 = NULL, *l2 = NULL, *p, *tmp;
    for(int i = 0; i < sizeof(arr1)/sizeof(int); ++i)
    {
        tmp = new ListNode(arr1[i]);
        if(!l1)
        {
            l1 = tmp;
        }
        else
        {
            p->next = tmp;
        }
        p = tmp;
    }
    for(int i = 0; i < sizeof(arr2)/sizeof(int); ++i)
    {
        tmp = new ListNode(arr2[i]);
        if(!l2)
        {
            l2 = tmp;
        }
        else
        {
            p->next = tmp;
        }
        p = tmp;
    }
    ListNode *res = solu.addTwoNumbers(l1, l2);
    tmp = res;
    while(tmp)
    {
        cout << tmp->val;
        if(tmp->next) cout << " -> ";
        tmp = tmp->next;
    }
    cout << endl;
    return 0;
}
