#include <iostream>
#include <set>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} ListNode, *ListPtr;

// create a list of length n and initialize the node data with arr[n]
ListPtr createLinkList(int n, int arr[])
{
    ListPtr p, r, list = NULL;
    //1->2->3->...->10
    for(int i = 0; i < n; ++i)
    {
        p = new ListNode;
        p->data = arr[i]; //i+1
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

ListPtr findNthLast(ListPtr head, int n)
{
    // NOTE the nth last and the last has dist of (n-1)
    if(!head || n <= 0) return NULL; //for empty linklist
    ListPtr r = head;
    for(int i = 0; i < n-1; ++i)
    {
        if(r)
        {
            r = r->next;
        }
        else
        {
            break;
        }
    }
    if(!r->next) return NULL;
    ListPtr p = head;
    while(r->next)
    {
        p = p->next;
        r = r->next;
    }
    return p;
}
// remove duplicates from an unsorted linklist
int main()
{
    const int listLen = 10;
    int arr[listLen] = {1, 2, 3, 4, 5, 89, 8, 66, 33, 12};
    ListPtr p, q;
    p = createLinkList(listLen, arr);
    q = p;
    cout << "Linklist content: " << endl;
    while(q)
    {
        cout << q->data;
        if(q->next) cout << " -> ";
        q = q->next;
    }
    cout << endl;
    
    //findNthLast
    int n = 3;
    // get the n-th last element (a node)
    ListPtr dst = findNthLast(p, n);
    if(dst)
    {
        cout << "The " << n << "th last element is " << dst->data << endl;  
    }
    else
    {
        // either list is empty, n <= 0, or n > listLen
        cout << "Invalid " << n << "th last element!" << endl;
    }   
    destroyLinkList(&p);
    return 0;
}

