// merge k sorted linked lists and return the resulting one sorted link. Analyze and describle its complexity.
// NOTE: VERY GOOD for complexity analysis !!!
// use priority queue: O(logm) * O(average(n_i)), where n_i length of ith list ==> not so good, further do it!!!
#include <iostream>
#include <vector>
#include <queue> // priority_queue
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Comp
{
    bool operator()(ListNode* la, ListNode* lb)
    {// NOTE: make sure top elem is the smallest 
        return la->val > lb->val; 
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0) return NULL;
        if(len == 1) return lists[0];
        ListNode* res = new ListNode(0);
        ListNode* pres = res;
        if(len == 2)
        {   
            ListNode *p1 = lists[0], *p2 = lists[1];
            while(p1 && p2)
            {
                if(p1->val < p2->val) {pres->next = p1; p1 = p1->next; }
                else {pres->next = p2; p2 = p2->next; }
                pres = pres->next;
            }
            if(p1) pres->next = p1;
            if(p2) pres->next = p2;
            return res->next; // skip pseudohead
        }
        
        priority_queue<ListNode*, vector<ListNode *>, Comp> pq;
        for(int i = 0; i < len; ++i) 
        {
            if(lists[i]) pq.push(lists[i]);
        }
        while(!pq.empty())
        {
            ListNode *tmp = pq.top(); pq.pop();
            pres->next = tmp; pres = pres->next;
            if(tmp->next) pq.push(tmp->next);
        }
        return res->next; //skip pseudohead
    }
};

int main()
{
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(4);
    h1->next->next = new ListNode(7);
    h1->next->next->next = new ListNode(66);

    ListNode *h2 = new ListNode(2);
    h2->next = new ListNode(5);
    h2->next->next = new ListNode(8);

    ListNode *h3 = new ListNode(3);
    h3->next = new ListNode(6);
    h3->next->next = new ListNode(9);
    
    vector<ListNode *> input;
    input.push_back(h1); input.push_back(h2); input.push_back(h3);
    
    Solution solu;
    ListNode *res = solu.mergeKLists(input);
    ListNode *tmp = res;
    while(tmp) {cout << tmp->val << " "; tmp = tmp->next; }
    cout << endl;
    return 0;
}
