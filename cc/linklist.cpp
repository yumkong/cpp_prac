#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} ListNode, *ListPtr;

// create a list of length n
ListPtr createLinkList(int n)
{
    ListPtr p, r, list = NULL;
    //1->2->3->...->10
    for(int i = 0; i < n; ++i)
    {
        p = new ListNode;
        p->data = i + 1;
        p->next = NULL;
        if(!list)
        {
            list = p;
        }  
        else
        {
            r->next = p;
        }
        //always point to the last node
        r = p;
    }
    // return head pointere
    return list;
}

// insert a node (with value e) after the node indicated by q
void insertNode(ListPtr *list, ListPtr q, int e)
{
    ListPtr p;
    p = new ListNode;
    p->data = e;
    if(!*list) // *list is an empty linklist
    {
        //need to change the head pointer's content, so must use ptr's ptr
        *list = p;
        p->next = NULL;
    }
    else
    {
        p->next = q->next;
        q->next = p;
    }
}

// delete node (pointed by q) from linklist
void delNode(ListPtr *list, ListPtr q)
{
    ListPtr r;
    //if q points to the 1st node
    if(q == *list) 
    {
        *list = q->next;
        delete q;
    }
    else
    {
        for(r = *list; r->next != q; r = r->next); //empty loop body
        if(r->next) //if q is found (r not reach the linklist tail)
        {
            r->next = q->next;
            delete q;
        }
    }
}

//after finishing all operation, destroy linklist
void destroyLinkList(ListPtr *list)
{
    ListPtr p, q;
    p = *list;
    while(p)
    {
        q = p->next;
        delete p;
        p = q;
    } 
    *list = NULL;
}

int main()
{
    ListPtr p, q;
    p = createLinkList(10);
    q = p;
    cout << "Linklist content: " << endl;
    while(q)
    {
        cout << q->data;
        if(q->next) cout << " -> ";
        q = q->next;
    }
    cout << endl;
    q = p; //repoint to the head
    cout << "After deleting 5th element: " << endl;
    for(int i = 0; i < 4; ++i)
    {
        q = q->next;
    }
    delNode(&p, q);
    q = p;
    while(q)
    {
        cout << q->data;
        if(q->next) cout << " -> ";
        q = q->next;
    }
    cout << endl;
    destroyLinkList(&p);

    return 0;
}
