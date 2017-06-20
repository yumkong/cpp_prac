#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 1000002;
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

bool match(Node *r1, Node *r2)
{
    if(!r1 && !r2) return true;
    else if(!r1 || !r2) return false;
    else if(r1->key != r2->key) return false;
    else return match(r1->lchild, r2->lchild) && match(r1->rchild, r2->rchild);
}

bool subtree(Node *r1, Node *r2)
{
    if(!r1) return false;
    else if(r1->key == r2->key)
    {
        if(match(r1, r2)) return true;
    }
    else
    {
        return subtree(r1->lchild, r2) || subtree(r1->rchild, r2);
    }
}

bool contain_tree(Node *r1, Node *r2)
{
    if(!r2) return true;
    else return subtree(r1, r2);
}

int main()
{
    init();
    int million = 524287; //2**19 - 1 ==> make it a complete binary tree that contains {0, 1, 2}
    int *a1 = new int[million];
    for(int i = 0; i < million; ++i)
    {
        a1[i] = i;
    }
    //int a1[] = {0, 1, 2, 3, 4, 5, 6};
    int a2[] = {0, 1, 2};
    Node *r1 = NULL, *r2 = NULL;
    create_minimal_tree(r1, NULL, a1, 0, million-1);
    create_minimal_tree(r2, NULL, a2, 0, 2);
    
    if(contain_tree(r1, r2)) cout << "r1 contains r2" << endl;
    else cout << "r1 does not contain r2" << endl;

    return 0;
}

