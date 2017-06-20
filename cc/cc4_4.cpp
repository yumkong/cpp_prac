#include <iostream>
#include <cstring> // memset
//#include <cmath>  //max
#include <vector>
#include <list>
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

vector<list<Node*> > find_level_linklists(Node *head)
{
    vector<list<Node*> > res; // the return vector
    int level = 0;
    list<Node*> li;
    li.push_back(head); // list of node
    res.push_back(li); // vector of list
    while(!res[level].empty())
    {
        list<Node*> l;
        list<Node*>::iterator it;
        for(it = res[level].begin(); it != res[level].end(); ++it)
        {
            Node *n = *it;
            if(n->lchild) l.push_back(n->lchild);
            if(n->rchild) l.push_back(n->rchild);
        }
        ++level;
        res.push_back(l);
    }
    return res;
}

void print(vector<list<Node*> > res)
{
    vector<list<Node*> >::iterator vit;
    for(vit = res.begin(); vit != res.end(); ++vit)
    {
        list<Node*> li = *vit;
        list<Node*>::iterator lit;
        for(lit = li.begin(); lit != li.end(); ++lit)
        {
            Node *n = *lit;
            cout << n->key << " ";
        }
        cout << endl;
    }
}

int main()
{
    init();
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 8);
    vector<list<Node*> > res;
    res = find_level_linklists(head);
    print(res);
    return 0;
}
