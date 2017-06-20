// find the first common ancestor of two nodes in a binary tree
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

const int MAX_N = 100;
// elements of tree
struct Node
{
    int key;
    Node *lchild, *rchild, *parent;
};

Node *p, node[MAX_N];
int cnt;

void init()
{
    p = NULL;
    memset(node, '\0', sizeof(node));
    cnt = 0;
}

// recursion to create tree
void create_minimal_tree(Node* &head, Node *parent, int a[], int start, int end)
{
    if(start <= end)
    {
        int mid = (start + end) >> 1;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        // recursion must have valid stop criterion
        // stops when (start > mid - 1) or (mid + 1 > end) 
        create_minimal_tree(head->lchild, head, a, start, mid - 1);
        create_minimal_tree(head->rchild, head, a, mid + 1, end);
    }

}

// search for a node with certain value (assume a binary search tree)
Node *search(Node *head, int x)
{
    if(head == NULL) return NULL;
    if(x == head->key) 
    {
        return head;
    }
    else if(x < head->key) 
    {
        search(head->lchild, x);
    }
    else 
    {
        search(head->rchild, x);
    }
}

//map is a like dict python, the key can be any data type
Node *first_ancestor(Node *n1, Node *n2)
{
    if(n1 == NULL || n2 == NULL) return NULL;
    map<Node*, bool> m;
    while(n1)
    {
        m[n1] = true;
        n1 = n1->parent;
    }
    while(n2 && !m[n2]) // if n2 not appear in map m
    {
        n2 = n2->parent; //from bottom to top => will find the first ansester
    }
    return n2; //if not found, n2 = NULL
}

int main()
{
    init();
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 8);
    Node *n1 = search(head, 0);
    Node *n2 = search(head, 6);
    cout << n1->key << " " << n2->key << endl;
    Node *ans = first_ancestor(n1, n2);
    cout << ans->key << endl;
    return 0;
}

