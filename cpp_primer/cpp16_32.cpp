#include <iostream>
using namespace std;
// the node in the queue linklist
template <typename Type> class QueueItem
{
public:
    Type item;  // value stored in this element
    QueueItem *next;
// private class, no public section
public:
    QueueItem(const Type &t): item(t), next(0) {}
};

template <typename Type> class Queue
{
private:
    QueueItem<Type> *head;
    QueueItem<Type> *tail;
    void destroy();
    void copy_elems(const Queue&);
public:
    // empty Queue
    Queue(): head(0), tail(0) {}
    // copy control to manage pointers to QueueItems in the Queue
    Queue(const Queue &Q): head(0), tail(0) { copy_elems(Q); }
    Queue& operator=(const Queue&);
    ~Queue() { destroy(); }
    // return element from head of Queue
    // unchecked operation: front on an empty Queue is undefined
    Type& front() {return head->item; }
    const Type &front() const {return head->item; }
    void push(const Type&);  // add element to the back of Queue
    void pop(); //remove element from head of Queue
    bool empty() const
    {
        return head == 0;
    }
};

template <typename Type> void Queue<Type>::destroy()
{
    while(!empty())
    {
        pop();
    }
}

template <typename Type> void Queue<Type>::pop()
{
    // pop is unchecked: poping off an empty Queue is undefined
    QueueItem<Type>* p = head;
    head = head->next;
    delete p;
}

template <typename Type> void Queue<Type>::push(const Type& val)
{
    //allocate a new QueueItem object
    // it is so easy to create a new node, just constructor is OK
    QueueItem<Type> *pt = new QueueItem<Type>(val);
    //put item onto existing Queue
    if(empty())
    {
	head = tail = pt;
    }
    else
    {
	tail->next = pt;
        tail = pt;
    }
}

template <typename Type> void Queue<Type>::copy_elems(const Queue &orig)
{
    // copy elems from orig into this Queue
    // loop stop when pt == 0, which happens when we reach orig.tail
    for(QueueItem<Type> *pt = orig.head; pt; pt = pt->next)
    {
        push(pt->item);
    }
}

template <typename Type>
Queue<Type>& Queue<Type>::operator=(const Queue& orig)
{
    destroy();
    copy_elems(orig);
    return *this;
}

int main()
{
    Queue<int> qi;
    short s = 666;
    int i = 531;
    qi.push(s); // s converted to int and passed to push
    qi.push(i);
    cout << qi.front() << endl;
    qi.pop();
    cout << qi.front() << endl;
    return 0;
}
