//check if a tree (binary tree is balanced ?)
// there can be no tree class (struct) when implementing a tree functionality
#include <iostream>
#include <cstring>
#include <cmath>  // max(a, b) in getHeight, abs()
using namespace std;

const int MAX_N = 100;
struct Node  // similar to a class
{
    int key;
    Node *lchild, *rchild, *parent;
};

//using recursion to calulate tree height
int getHeight(Node *head)
{
    if(!head)
    {
        return 0; //empty tree height is 0
    }
    else
    {
        return max(getHeight(head->lchild), getHeight(head->rchild)) + 1;
    }
}

//using recursion to insert element to tree
void insert(Node* &head, Node* &p, Node (&tnode)[MAX_N], int &cnt, int x)
{
    if(!head)
    {
        tnode[cnt].key = x;
        tnode[cnt].parent = p;
        head = &tnode[cnt++];
        return;
    }
    p = head;
    if(x < head->key)
    {
        insert(head->lchild, p, tnode, cnt, x);
    }
    else
    {
        insert(head->rchild, p, tnode, cnt, x);
    }
}

//using recursion to get depth of each leaf node
void getDepth(Node *head, int &d, int &num, int (&dep)[MAX_N])
{
    // num records total num of leaf nodes
    if(!head) return;
    ++d;
    getDepth(head->lchild, d, num, dep);
    if(!head->lchild && !head->rchild)
    {
        dep[num++] = d;
    }
    getDepth(head->rchild, d, num, dep);
    --d;
}

//using recursion to check balance
bool checkBalance(Node *head)
{
    if(!head) return true; //think null tree as balanced
    int diff = getHeight(head->lchild) - getHeight(head->rchild);
    if(abs(diff) > 1)
    {
        return false;
    }
    else
    {
        return checkBalance(head->lchild) && checkBalance(head->rchild);
    }
}

//using getDepth to get depth of all leaves, if (max - min <=1) then balanced
bool checkBalance2(Node *head, int (&dep)[MAX_N], int &num)
{
    if(!head) return true; // think null tree as balanced
    int maxd = dep[0], mind = dep[0];
    for(int i = 0; i < num; ++i)
    {
        if(dep[i] > maxd) maxd = dep[i];
        if(dep[i] < mind) mind = dep[i];
    }
    if(maxd - mind > 1)
    { 
        return false;
    }
    else
    { 
        return true;
    }
}

int main()
{ 
    // tree components
    Node *head, *p, tnode[MAX_N];
    // initialize tree
    head = p = NULL;
    cout << "tnode takes up " << sizeof(tnode) << " bytes." << endl;
    memset(tnode, '\0', sizeof(tnode));
    int cnt = 0;
    // create tree
    int arr[12] = {88, 3, 5, 6, 9, 1, 22, 12, 2, 666, 90, 0};
    for(int i = 0; i < 12; ++i)
    {
        insert(head, p, tnode, cnt, arr[i]);
    }
    //get depth and show (just for verification purpose)
    int d = 0, num = 0, dep[MAX_N];
    getDepth(head, d, num, dep);
    for(int i = 0; i < num; ++i)
    {
        cout << dep[i] << " ";
    }
    cout << endl;
    // check balance
    cout << "Tree balance: " << checkBalance(head) << endl;
    cout << "Tree balance (alternative): " << checkBalance2(head, dep, num) << endl;
    // not need to release space because here we use a fixed-length array to save each node
    return 0;
}


