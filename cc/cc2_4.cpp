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
// NOTE: the following is wrong-> must use reference or pointer's pointer to change the 1st 
// pointer's content
//void destroyLinkList(lnode *list)
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

lnode *addLinkList(lnode *a, lnode *b)
{
    int upflow = 0;
    int sum;
    lnode *listsum = NULL;
    lnode *p, *q; 
    while(a && b)
    {
        sum = a->data + b->data + upflow;
        q = new lnode;
        q->data = sum % 10;
        upflow = sum / 10; // for next digit's addition
        q->next = NULL;
        if(listsum)
        {
            p->next = q;
        }
        else
        {
            listsum = q;
        }
        p = q;
        // go to next digit
        a = a->next;
        b = b->next;
    }
    lnode *remainlist;
    if(a)
    {
        remainlist = a;
    }
    else
    {
        remainlist = b; // evenif both a and b are empty, still ok
    }
    while(remainlist)
    {
        sum = remainlist->data + upflow;
        q = new lnode;
        q->data = sum % 10;
        q->next = NULL;
        upflow = sum / 10; 
        if(listsum) p->next = q;
        else listsum = q;
        p = q;
        remainlist = remainlist->next;
    }
    if(upflow > 0)
    {
        q = new lnode;
        q->data = 1;
        q->next = NULL;
        if(listsum) p->next = q;
        else listsum = q;
        p = q;
    }
    return listsum;
}

int main()
{
    const int num1 = 3;
    const int num2 = 3;
    int arr1[num1] = {6, 7, 8};
    int arr2[num2] = {6, 6, 6};
    lnode *list1 = createLinkList(num1, arr1);
    lnode *list2 = createLinkList(num2, arr2);
    cout << "1st operand: " << endl;
    printLinkList(list1);
    cout << "2nd operand: " << endl;
    printLinkList(list2);
    // add two list
    lnode *listsum = addLinkList(list1, list2);
    cout << "sum: " << endl;
    printLinkList(listsum);
    // destroy
    destroyLinkList(list1);
    destroyLinkList(list2);
    destroyLinkList(listsum);
}
