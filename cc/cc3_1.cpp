// use an array to hold 3 stacks
#include <iostream>
using namespace std;

class stack3
{
private:
    int *buf;
    int ptop[3];// index of the top of each stack
    int size;  // size of each stack 
public: 
    stack3(int perstacksize = 100)
    {
        buf = new int[perstacksize * 3];
        ptop[0] = 0; // point to idx=0, meaning that there is no element currently 
        ptop[1] = 0;
        ptop[2] = 0;
        size = perstacksize;
    }
    ~stack3()
    {
        if(buf)
        { 
            delete [] buf;
        }
    }
    // stackIdx = 0, 1 or 2
    void push(int stackIdx, int val)
    {
        //if(ptop[stackIdx] >= size) return false
        int element_idx = size * stackIdx + ptop[stackIdx];
        buf[element_idx] = val;
        ++ptop[stackIdx]; // point to the 1st unintiialized cell index
    }
    // return popped value
    int pop(int stackIdx)
    {
        // if(ptop[stackIdx] <= 0) return false
        --ptop[stackIdx];
        int element_idx = size * stackIdx + ptop[stackIdx];
        return buf[element_idx];
    }
    // only get the value of the top element but no pop 
    int top(int stackIdx)
    {
        // if(ptop[stackIdx] <= 0) return false
        int element_idx = size * stackIdx + ptop[stackIdx] - 1;
        return buf[element_idx];
    }
    bool isempty(int stackIdx)
    {
        return (ptop[stackIdx] == 0);
    }
};

int main()
{
    stack3 mystack;
    for(int i = 0; i < 50; ++i) mystack.push(0, i);
    for(int i = 60; i < 90; ++i) mystack.push(1, i);
    for(int i = 1000; i < 1080; ++i) mystack.push(2, i);
    cout << "Top three elements of stack 0: " << endl;
    cout << mystack.pop(0) << endl;
    cout << mystack.pop(0) << endl;
    cout << mystack.pop(0) << endl;
    cout << "Top three elements of stack 1: " << endl;
    cout << mystack.pop(1) << endl;
    cout << mystack.pop(1) << endl;
    cout << mystack.pop(1) << endl;
    cout << "Top three elements of stack 2: " << endl;
    cout << mystack.pop(2) << endl;
    cout << mystack.pop(2) << endl;
    cout << mystack.pop(2) << endl;
    return 0;
}

