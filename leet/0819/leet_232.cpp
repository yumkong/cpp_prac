// implement Queue using Stacks
// Assume that all operations are valid (no pop or peek operations will be called on an empty queue)
// NOTE: must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty

#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
private: 
    stack<int> st1;
    stack<int> st2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        // do nothing
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(st1.empty()) 
        {
            st1.push(x);
            stack<int> tmp;
            while(!st2.empty()) 
            {
                tmp.push(st2.top()); 
                st2.pop(); 
            }
            while(!tmp.empty()) 
            {
                st1.push(tmp.top()); 
                tmp.pop(); 
            }
        }
        else
        {
            st2.push(x);
            stack<int> tmp;
            while(!st1.empty()) 
            {
                tmp.push(st1.top()); 
                st1.pop(); 
            }
            while(!tmp.empty())
            {
                st2.push(tmp.top());
                tmp.pop();
            }
        }  
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp;
        if(!st1.empty()) { tmp = st1.top(); st1.pop(); }
        else { tmp = st2.top(); st2.pop(); }
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        if(!st1.empty()) return st1.top();
        else return st2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (st1.empty() && st2.empty());
    }
};

int main()
{
    MyQueue obj;
    obj.push(2);
    obj.push(66);
    obj.pop();
    cout << obj.peek() << endl;
    cout << obj.empty() << endl;
    return 0;
}
