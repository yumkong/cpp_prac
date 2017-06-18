// detect loop in linklist
#include <iostream>
#include <map>
using namespace std;

typedef struct node
{
    int data;
    node *next;
} lnode;

// use an array to initialize a linklist with lenght of n
lnode *createLinkListLoop(int n, int arr[], int loopidx)
{
    if(n <= 0) return NULL;
    //NOTE: it's very important to intialize list with NULL, otherwise segmentation fault
    lnode *list = NULL;
    lnode *p, *q, *t; // t is for recording the looping node
    for(int i = 0; i < n; ++i)
    {
        q = new lnode;
        q->data = arr[i];
        q->next = NULL;
        if(list)
        {
            p->next = q;
            p = q;
        }
        else
        {
            list = q;
            p = list;
        }
		if(i == loopidx) t = q;
    }
	p->next = t;// tail points back to the loopidx node
    return list;
}
// NOTE: the following is wrong-> must use reference or pointer's pointer to change the 1st 
// pointer's content
//void destroyLinkList(lnode *list)
void destroyLinkListLoop(lnode *(&list), map<lnode *, bool> &hash)
{
    if(!list) return;
    lnode *p, *q;
    p = list;
    while(p)
    {
        q = p;
        p = p->next;
		if(hash[q])
		{
			break; //break while loop when loop occurs
		}
		else
		{
			hash[q] = true;
			delete q;
		}
    }
    list = NULL;
}

void printLinkListLoop(lnode *head, int len)
{
    if(!head) return;
	int i = 0;
    while(head && i < len)
    {
        cout << head->data;
        if(head->next) cout << " -> ";
        head = head->next;
		++i;
    }
    cout << endl;
}

lnode *findLoopStart(lnode *list, map<lnode *, bool> &hash)
{
	while(list)
	{
		if(hash[list]) return list;
		else
		{
		    //1st time a key is added, its value is 0 (false) by default
            hash[list] = true;
            list = list->next;			
		}
	}
	//if come here, meaning no looped node
	return list;
}

int main()
{
    const int num = 10;
	int m = 6;
    int arr[num] = {6, 7, 8, 9, 121, 12, 66, 8, 9, 100};
    lnode *list = createLinkListLoop(num, arr, m);
    //cout << "Original linklist: " << endl;
    //printLinkListLoop(list, num);
    // lnode * as key ==> guarantee each node only appear once, if twice, that is a loop
	map<lnode *, bool> hash;
    lnode *loopnode = findLoopStart(list, hash);
	if(loopnode)
        cout << "The value of the beginning node of loop: " << loopnode->data << endl;
	else
		cout << "No loop!" << endl;
    // destroy
	hash.clear();
    destroyLinkListLoop(list, hash);
}
