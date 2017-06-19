// implements a queue using two stacks
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class MyQueue
{
private:
    stack<T> sin, sout;
public:
    MyQueue() {}
    ~MyQueue() {}
    bool isempty()
    {
        return sin.empty() && sout.empty();
    }
    
    void move(stack<T> &src, stack<T> &dst)
    {
        while(!src.empty())
        {
            dst.push(src.top());
            src.pop();
        }
    }
    void push(T val)
    {
        move(sout, sin);
        sin.push(val);
    }
    void pop()
    {
        move(sin, sout);
        sout.pop();    
    }
    T front()
    {
        move(sin, sout);
        return sout.top();
    }
    T back()
    {
        move(sout, sin);
        return sin.top();
    }
    //implicitly convert from size_type to int as return value type
    int size()
    {
        return sin.size() + sout.size();
    }
};

int main()
{
    MyQueue<int> q;
    for(int i = 0; i < 12; ++i)
    {
        q.push(i);
    }
    cout << "Original: " << endl;
    cout << "Queue front: " << q.front() << ", rear: " << q.back() << endl;
    cout << "After popping twice: " << endl;
    q.pop();
    q.pop();
    cout << "Queue front: " << q.front() << ", rear: " << q.back() << endl;
    return 0;
}
