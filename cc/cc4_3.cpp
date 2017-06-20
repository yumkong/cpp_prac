#include <iostream>
#include <cstring> // memset
#include <cmath>  //max
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

int height(Node *head)
{
    if(head == NULL) return 0;
    return max(height(head->lchild), height(head->rchild)) + 1;
}

int main()
{
    init();
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 8);
    cout << "tree height = " << height(head) << endl;
    cout << "print tree from top to bottom: " << endl;
    for(int i = 0; i < cnt; ++i)
    {
        cout << node[i].key << " ";
    }
    cout << endl;
    return 0;
}
