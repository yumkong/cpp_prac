// merge two sorted lists
// not mention whether the list is in descending order or ascending order => assume it as ascending
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *pl1 = l1, *pl2 = l2;
        ListNode *reshead = NULL, *resptr = NULL;
        while(pl1 && pl2)
        {
            int val; 
            if(pl1->val < pl2->val)
            {
                val = pl1->val;
                pl1 = pl1->next;
            }
            else
            {
                val = pl2->val;
                pl2 = pl2->next;
            }
            ListNode *tmp = new ListNode(val);
            if(!reshead) 
            {
                reshead = tmp;
                resptr = reshead;
            }
            else
            {
                resptr->next = tmp;
                resptr = resptr->next;
            }
        }
        ListNode *remainPtr = NULL;
        if(pl1) remainPtr = pl1;
        else if(pl2) remainPtr = pl2;
        while(remainPtr)
        {
            int val = remainPtr->val;
            ListNode *tmp = new ListNode(val);
            resptr->next = tmp;
            resptr = resptr->next;
            // go to next node
            remainPtr = remainPtr->next;
        }
        return reshead;
    }
};

int main()
{
    int a1[] = {1, 3, 5, 7, 9};
    int b1[] = {2, 4};
    ListNode *a = NULL, *ap = NULL, *b = NULL, *bp = NULL, *c = NULL, *cp = NULL;
    for(int i = 0; i < 5; ++i)
    {
        ListNode *tmp = new ListNode(a1[i]);
        if(!a) {a = tmp; ap = a;}
        else {ap->next = tmp; ap = ap->next; }
    }
    for(int i = 0; i < 2; ++i)
    {
        ListNode *tmp = new ListNode(b1[i]);
        if(!b) {b = tmp; bp = b;}
        else {bp->next = tmp; bp = bp->next; }
    }
    
    Solution solu;
    c = solu.mergeTwoLists(a, b);
    cp = c;
    while(cp) 
    {     
        cout << cp->val << endl;
        cp = cp->next;
    }
    return 0;
}
