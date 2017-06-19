// push() pop() and min() all in O(1) time
// following mainly inspired by Hawstein
#include <iostream>
using namespace std;

//const int MAX_INT = ~(1<<31);
#define getmin(a, b) ((a)<(b)?(a):(b))
 
typedef struct node
{
    int val;
    int minval;
}node;

class StackWithMin
{
private:
    node *buf;
    int cur; //top idx
public:
    StackWithMin(int stacksize = 100)
    {
        buf = new node[stacksize];
        cur = 0;
    }
    ~StackWithMin()
    {
        if(buf)
        {
            delete [] buf;
        }
    }
    void push(int val)
    {
        // need to consider border issue later
        if(cur > 0) 
        {
            buf[cur].val = val;
            buf[cur].minval = getmin(val, buf[cur-1].minval);
        }
        else //cur == 0
        {
            buf[cur].val = val;
            buf[cur].minval = val;
        }
        ++cur;
    }
    int pop()
    {
        //need to consider border issue later
        --cur;
        return buf[cur].val;
    }
    int top()
    {
        return buf[cur-1].val;
    }  
    bool isempty()
    {
        return (cur == 0);
    }
    int min()
    {
        return buf[cur-1].minval;
    }
};

int main()
{
    StackWithMin mystack;
    int arr[10] = {12, 4, 23, 65, 3, 5, 21, 2, 1, 23};
    for(int i = 0; i < 10; ++i) mystack.push(arr[i]);
    cout << "stack min: " << mystack.min() << endl;
    cout << "stack top: " << mystack.top() << endl;
    cout << "pop 2 elems from top: " << mystack.pop() << ", " << mystack.pop() << endl;
    cout << "stack min: " << mystack.min() << endl;
    cout << "stack top: " << mystack.top() << endl;
    return 0;
}
