//sort elements in stack
#include <iostream>
#include <cstdlib>   // rand()
#include <stack>
#include <queue> // priority_queue
using namespace std;

// sort the stack via a queue (priority_queue)
void Qsort(stack<int> &s)
{
    priority_queue<int, vector<int>, greater<int> > q;
    while(!s.empty())
    {
        q.push(s.top());
        s.pop(); // when quiting while, s is popped to empty
    }
    while(!q.empty())
    {
        s.push(q.top());
        q.pop();
    }
}

stack<int> Ssort(stack<int> s)
{
    stack<int> dst;
    while(!s.empty())
    {
        int data = s.top();
        s.pop();
        while(!dst.empty() && dst.top() > data)
        {
            s.push(dst.top());
            dst.pop();
        }
        dst.push(data);
    }
    // at last, assign
    //s = t;
    return dst;
}

int main()
{
    //model for generating random integers
    srand((unsigned)time(0));
    stack<int> s;
    for(int i = 0; i < 10; ++i)
    {
        // push int in range 0~99
        s.push(rand()%100);
    }
    stack<int> t = Ssort(s); // Qsort(s)
    cout << "Initial stack: " << endl;
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    cout << "After sorting: " << endl;
    while(!t.empty())
    {
        cout << t.top() << " ";
        t.pop();
    }
    cout << endl;
    return 0;
}
