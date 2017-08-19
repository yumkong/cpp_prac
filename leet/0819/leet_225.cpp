// implement stack using queues
// only push to back, peek/pop from front, size, and is empty operations are valid.
#include <queue>
#include <iostream>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        // do nothing
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(q1.empty()) 
        { 
            q1.push(x);
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else
        {
            q2.push(x);
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp;
        if(!q1.empty()) {tmp = q1.front();  q1.pop(); }
        else {tmp = q2.front(); q2.pop(); }
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        if(!q1.empty()) return q1.front();
        else return q2.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (q1.empty() && q2.empty());
    }
};

int main()
{
    MyStack obj;
    obj.push(2);
    obj.push(66);
    obj.push(19);
    cout << obj.pop() << endl;
    cout << obj.top() << endl;
    cout << obj.empty() << endl;
    return 0;
}
