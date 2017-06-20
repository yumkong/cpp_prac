#include <iostream>
#include <vector>
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

void print(Node *head, int level)
{
    vector<int> v;
    //push the tree from bottom to top
    for(int i = 0; i < level; ++i)
    {
        v.push_back(head->key);
        head = head->parent;
    }
    // print the tree from top to bottom
    while(!v.empty())
    {
        cout << v.back() << " ";
        v.pop_back();
    }
    cout << endl;
}

void find_sum(Node *head, int sum)
{
    if(!head) return;
    Node *a = head;
    int tmp = 0;
    for(int i = 1; a != NULL; ++i)
    {
        tmp += a->key;
        if(tmp == sum)
        {
            print(head, i);
        }
        a = a->parent;
    }
    find_sum(head->lchild, sum);
    find_sum(head->rchild, sum);
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
    Node *r1 = NULL;
    create_minimal_tree(r1, NULL, a1, 0, million-1);

    find_sum(r1, 666666);
    return 0;
}

