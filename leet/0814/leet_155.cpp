// design a stack that supports push, pop, top and retrieving the minimum elem in O(1)
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> stmin;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(stmin.empty() || stmin.top() > x) stmin.push(x);
        else stmin.push(stmin.top());
    }
    
    void pop() {
        st.pop();
        stmin.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return stmin.top();
    }
};

int main()
{
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout << obj.getMin() << endl; // -3
    obj.pop();
    cout << obj.top() << endl; // 0
    cout << obj.getMin() << endl; // -2
    return 0;
}
