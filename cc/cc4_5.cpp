// find the next node of a given node in a binary search tree
#include <iostream>
#include <cstring> // memset
//#include <cmath>  //max
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
        node[cnt].parent = parent; // tree root node's parent is NULL
        head = &node[cnt++];
        // recursion must have valid stop criterion
        // stops when (start > mid - 1) or (mid + 1 > end) 
        create_minimal_tree(head->lchild, head, a, start, mid - 1);
        create_minimal_tree(head->rchild, head, a, mid + 1, end);
    }

}

Node *minimal(Node *a)
{
    if(a == NULL) return NULL;
    while(a->lchild)
    {
        a = a->lchild;
    }
    return a;
}

Node *successor(Node *a)
{
    if(a == NULL) return NULL;
    // if having right child, get the minimal of the subtree with head being the right child
    if(a->rchild) return minimal(a->rchild);
    Node *y = a->parent;
    // when current node being the left node, continuing go upward until the node become a left node
    while(y && y->rchild == a)
    {
        a = y;
        y = y->parent;
    }
    return y;
}

int main()
{
    init();
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 8);
    cout << "the head's rchild is " << head->rchild->key << endl;
    cout << "the successor of head's rchild is: " << (successor(head->rchild))->key << endl;

    return 0;
}
