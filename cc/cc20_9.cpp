// numbers are randomly generated and passed to a method, find and maintain the median value as new values are generated
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib> // memset?
using namespace std;

class Median
{
private:
    // for a queue: leftmost element is tail, rightmost is head (top)
    priority_queue<int, vector<int>, less<int> > max_heap; // smaller numbers
    priority_queue<int, vector<int>, greater<int> > min_heap; // bigger numbers
public:
    void Insert(int v);
    int GetValue();
};

void Median::Insert(int v)
{
    // if all empty, insert to max_heap
    if(max_heap.empty() && min_heap.empty()) 
    {
        max_heap.push(v);
    }
    else if(!max_heap.empty() && min_heap.empty()) 
    {
        max_heap.push(v);
    }
    else if(max_heap.empty() && !min_heap.empty())
    {
        min_heap.push(v);
    }
    else
    {
        // max_heap contains all smaller numbers, with top the biggest
        if(v < max_heap.top())
        {
            max_heap.push(v);
        }
        else // min_heap contains all bigger numbers, with top the smallest
        {
            min_heap.push(v);
        }
    }
    // moderate, make sure two heap's elems number diff not exceeding 1
    // not using max_heap.size() - min_heap.size() > 1
    // since size() return unsigned type (size_t) when subtracting result is negative
    // it turns to be a big positive making the logic true (however, false is what is supposed to be)
    while(max_heap.size() > min_heap.size() + 1)
    {
        // give the smallest to the bigger group?
        int data = max_heap.top();
        min_heap.push(data);
        max_heap.pop();
    }
    while(min_heap.size() > max_heap.size() + 1)
    {
        // give the biggest to the smaller group?
        int data = min_heap.top();
        max_heap.push(data);
        min_heap.pop();
    }
}

int Median::GetValue()
{
    if(max_heap.empty() && min_heap.empty())
    {
        return (1 << 31);// if all emptys, return int_min
    }
    if(max_heap.size() == min_heap.size())
    {
        // if even elems, average the middle two numbers
        return (max_heap.top() + min_heap.top()) / 2;
    }
    else if(max_heap.size() > min_heap.size())
    {
        return max_heap.top();
    }
    else
    {
        return min_heap.top();
    }
}

int main()
{
    Median md;
    md.Insert(3);
    md.Insert(1);
    md.Insert(2);
    cout << md.GetValue() << endl;
    return 0;
}
