//write your own stack class which does push(), pop() and getMax() in O(1)
#include <stack>
#include <iostream>
using namespace std;

class myStack{
private:
    stack<int> stackmain;
    stack<int> stackmax;
public:
    void push(int e)
    {
        stackmain.push(e);
        //stackmax is empty or the new element is larger
        if(stackmax.empty() || stackmax.top() < e) stackmax.push(e);
        else stackmax.push(stackmax.top());
    }
    int pop()
    {
        // stackmain, stackmax has the same size, so only use one for check empty
        if(!stackmain.empty())
        {
            int tmp = stackmain.top();  stackmain.pop();
            stackmax.pop(); // stackmax pop() accordingly
            return tmp;
        }
        else
        {
            cout << "Empty stack!" << endl;
            return -666;
        }
    }
    int getMax()
    {
        return stackmax.top();
    }
    bool empty()
    {
        return stackmain.empty();
    }
};

int main()
{
    int a[] = {6,5,3,4,7,8,-1,80};
    int len = sizeof(a) / sizeof(a[0]);
    myStack ms;
    for(int i = 0; i < len; ++i) ms.push(a[i]);
    cout << "top | max" << endl;
    while(!ms.empty())
    { 
        cout << ms.getMax() << "     ";
        cout << ms.pop() << endl;
    }
    return 0;
} 
