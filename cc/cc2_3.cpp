#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
} lnode;

// use an array to initialize a linklist with lenght of n
lnode *createLinkList(int n, int arr[])
{
    if(n <= 0) return NULL;
    //NOTE: it's very important to intialize list with NULL, otherwise segmentation fault
    lnode *list = NULL;
    lnode *p;
    for(int i = 0; i < n; ++i)
    {
        lnode *q = new lnode;
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
    }
    return list;
}

void destroyLinkList(lnode *(&list))
{
    if(!list) return;
    lnode *p, *q;
    p = list;
    while(p)
    {
        q = p;
        p = p->next;
        delete q;
    }
    list = NULL;
}

void printLinkList(lnode *head)
{
    if(!head) return;
    while(head)
    {
        cout << head->data;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

bool delCertainNode(lnode *(&p))
{
    if(!p->next || !p)
    {
        //delete p; //NOTE: when the node is at the end, the p->data become 0, but not removed
        return false;
    }
    
    //assign the data of p->next to p and delete p->next
    lnode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    delete q;
    q = NULL;
    return true;
}

int main()
{
    const int num = 10;
    int arr[num] = {32, 2, 3, 666, 5, 6, 7, 8, 9, 66};
    lnode *head = createLinkList(num, arr);
    printLinkList(head);
    lnode *p = head;
    int idx = 9;
    for(int j = 0; j < idx; ++j)
    {
        p = p->next;
    }
    // remove a certain node p, given only access to that node
    delCertainNode(p);
    cout << "After removing the " << idx << " th node: " << endl;
    printLinkList(head);
    destroyLinkList(head);
}
