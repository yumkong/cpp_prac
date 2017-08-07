// a linked list is given s.t. each node contains an additional random pointer
// that can point to any node in the list or NULL, return a deep copy of the list
// NOTE the following solu is from @liaison, thanks!!!
#include <iostream>
using namespace std;

//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		if(!head) return NULL;
        RandomListNode *it = head, *next = NULL;
		// step1: make copy of each node and alternatively link original node/
		// with its copy
		while(it)
		{
			next = it->next;
			RandomListNode *cp = new RandomListNode(it->label);
			it->next = cp;
			cp->next = next;
			it = next;
		}
		//step2: assign random pointers for the copy nodes
        // this is key to this idea: it->random->next is actually
        // it->random node's corresponding copy position
        it = head;
		while(it)
		{
			if(it->random) it->next->random = it->random->next;
			it = it->next->next;
		}
		// step3: decouple the original and copy lists
		it = head;
		// pseudohead for copy list: avoid if condition in while loop
		RandomListNode *pseudohead = new RandomListNode(0);
		RandomListNode *cpit = pseudohead;
		while(it)
		{
			next = it->next->next;
			cpit->next = it->next;
			cpit = cpit->next;
			// restore original list
			// NOTE: since need to assign both it and it->next, use 
			// a tmp pointer "next" is necessary
			it->next = next;
			it = next;
		}
		return pseudohead->next;
    }
};

int main()
{
	RandomListNode *h1 = new RandomListNode(1);
    h1->next = new RandomListNode(2);
    h1->next->next = new RandomListNode(3);
    h1->next->next->next = new RandomListNode(4);
	h1->next->next->next->next = new RandomListNode(6);
	h1->random = h1->next->next->next;
	h1->next->random = h1;
	h1->next->next->random = h1->next->next;
	h1->next->next->next->random = h1;
	h1->next->next->next->next->random = h1->next->next;
	
	Solution solu;
	RandomListNode *res = solu.copyRandomList(h1);
	while(res)
	{
		cout << res->random->label << " ";
		res = res->next;
	}
	cout << endl;
	return 0;
}