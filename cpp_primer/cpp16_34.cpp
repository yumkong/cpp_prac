#include <iostream>
#include <stdexcept>      // std::out_of_range
using namespace std;

template <typename Type> class List;
template <typename Type> class ListItem
{
    friend class List<Type>;
    // private class, no public parts
    Type item;
    ListItem *next;
    ListItem(const Type &t): item(t), next(0) {}
};

template <typename Type> class List
{
private:
    // pointing to the head and tail elements of a list
    ListItem<Type> *front, *end; 
    void destroy();
    void copy_elems(const List&);
public:
    //default constructor
    List(): front(0), end(0) {}
    // copy control member
    List(const List& l): front(0), end(0)
    {
        copy_elems(l);
    }
    //
    List& operator=(const List&);
    ~List()
    {
        destroy();
    }
    //others
    void insert(ListItem<Type> *ptr, const Type& value);
    void del(ListItem<Type> *ptr);
    ListItem<Type> *find(const Type& value);
    ListItem<Type> *first()
    {
        return front;
    }
    ListItem<Type> *last()
    {
        return end;
    }
    bool empty() const
    {
        return (front == 0);
    }
    Type& getElem(ListItem<Type> *ptr)
    {
        //unchecked
        return ptr->item;
    }
    void printElem();
};

// delete all elems of List
template <typename Type>
void List<Type>::destroy()
{
    while(!empty())
    {
        del(front);
    }
}

// delete the elem pointed by ptr
template <typename Type>
void List<Type>::del(ListItem<Type> *ptr)
{
    //uncheck ptr
    ListItem<Type>* p = front;
    //obtain p that points to elem prior to ptr
    while(p != ptr && p != 0 && p->next != ptr)
    { p = p->next; }
    if(p != 0) // ptr really points to a elem of List
    {
        // the 1st elem to be deleted
        if(p == ptr)
        {
            front = ptr->next;
        }
        else //not point to the 1st element
        {
            p->next = ptr->next;
        }
        // the last element to be deleted
        if(ptr == end)
        {
            end = p;
            //end = p->next;
        }
        delete ptr;
    }
    else
    {
        throw out_of_range("no such element.");   
    }
}

//insert after the elem pointed by ptr
template <typename Type>
void List<Type>::insert(ListItem<Type> *ptr, const Type& val)
{
    // uncheck ptr
    ListItem<Type> *pt = new ListItem<Type>(val);
    // insert ListItem into List
    if(empty())
    {
        front = pt;
    }
    else
    {
        pt->next = ptr->next;
        ptr->next = pt;
    }
    if(ptr == end)
    {
        end = pt;
    }
}

//copy elems in orig to this List
template <typename Type>
void List<Type>::copy_elems(const List &orig)
{
    //end loop when pt == 0
    for(ListItem<Type> *pt = orig.front; pt; pt = pt->next)
    {
        insert(end, pt->item);
    }
}

//assignment operator, copy all elems
template <typename Type>
List<Type>& List<Type>::operator=(const List &orig)
{
    front = end = 0; // do not need to delete the link list?
    copy_elems(orig);
    return *this;
}

//check the element with Item val and return its pointer
template <typename Type>
ListItem<Type>* List<Type>::find(const Type& value)
{
    ListItem<Type>* pt = front;
    while(pt && pt->item != value)
    {
        pt = pt->next;
    }
    return pt;
}

template <typename Type>
void List<Type>::printElem()
{
    for(ListItem<int> *pt = this->first(); pt; pt = pt->next)
    {
        cout << pt->item << " ";
    }
    cout << endl;
}

int main()
{
    List<int> il;
    il.insert(0, 66);
    il.insert(il.first(), 66);
    il.insert(il.first(), 78);
    il.insert(il.last(), 1);
    il.insert(il.first(), 14);
    il.insert(il.last(), 17);
    il.insert(il.first(), 32);
    il.del(il.last());
    cout << "List elems are: " << endl;
    //***NOTE: because main() is not a friend func of class ListItem, it cannot get pt's private val (next)
    //for(ListItem<int> *pt = il.first(); pt; pt = pt->next)
    //{
    //    cout << pt->item << " ";
    //}
    // Solu: write another function inside List to print all its elements
    il.printElem();
    //finally, List<int> will be released automatically with ~List
    //il.destroy();
}
