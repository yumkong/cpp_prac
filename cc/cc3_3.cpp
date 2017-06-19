#include <iostream>
using namespace std;

const int STACK_SIZE = 100;
const int STACK_NUM = 10;

class stack
{
private:
    int *buf;
    int cur;
    int capacity;
public:
    stack(int capa = STACK_SIZE)
    {
        buf = new int[capa];
        cur = 0;
        capacity = capa;
    }
    ~stack()
    {
        delete [] buf;
    }
    void push(int val) 
    {
        // consider border issue
        buf[cur] = val;
        ++cur;
    }
    int pop() 
    { 
        // consider border issue
        --cur;
        return buf[cur];
    }
    int top() 
    {
        // border issue
        return buf[cur - 1];
    }
    bool isempty()
    {
        return (cur == 0);
    }
    bool full()
    {
        return (cur == capacity);
    }
};

class SetofStacks
{
private:
    stack *st;
    int cur_st;
    int capacity;
public:
    SetofStacks(int capa = STACK_NUM)
    {
        st = new stack[capa];
        cur_st = 0;
        capacity = capa;
    }
    ~SetofStacks()
    {
        delete [] st;
    }
    void push(int val)
    {
        if(st[cur_st].full()) ++cur_st;
        st[cur_st].push(val);
    }
    int pop()
    {
        if(st[cur_st].isempty()) --cur_st;
        return st[cur_st].pop();
    }
    int top()
    {
        if(st[cur_st].isempty()) --cur_st;
        return st[cur_st].top();
    }
    bool isempty()
    {
        return (cur_st == 0 && st[cur_st].isempty());
    }
    bool full()
    {
        return (cur_st == capacity-1 && st[cur_st].full());
    }
    int popAt(int idx)
    {
        return st[idx].pop();
    }
};

int main()
{
    SetofStacks sstack;
    for(int i = 0; i < 3*STACK_SIZE + 6; ++i)
    {
        sstack.push(i);
    }
    int cnt = 0;
    cout << "Pop from stack 0: " << endl;
    for(int i = 0; i < STACK_SIZE - 1; ++i)
    {
        ++cnt;
        cout << sstack.popAt(0) << " ";
        if(cnt == 10)
        {
            cnt = 0;
            cout << endl; 
        }
    }
    cnt = 0;
    cout << endl << "Pop from stack 2: " << endl;
    for(int i = 0; i < STACK_SIZE - 1; ++i)
    {
        //cout << endl;
        ++cnt;
        cout << sstack.popAt(2) << " ";
        if(cnt == 10)
        {
            cnt = 0;
            cout << endl;
        }
    }
    cout << endl << "The remaining of setstacks: " << endl;
    cnt = 0;
    while(!sstack.isempty())
    {
        ++cnt;
        cout << sstack.pop() << " ";
        if(cnt == 10)
        {
            cnt = 0;
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}
