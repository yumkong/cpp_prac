// smart pointer
#include <iostream>
#include <cstdlib>
using namespace std;

//this class can provide a pointer to any class <T>
template <typename T>
class SmartPointer
{
protected:
    T *ref;
    unsigned *ref_count;
private:
    //an inner function
    void clear()
    {
        delete ref;
        delete ref_count;
        ref = NULL; // avoid becoming a lost pointer
        ref_count = NULL;
    }
public:
    SmartPointer(T* ptr)
    {
        ref = ptr;
        ref_count = new unsigned();
        *ref_count = 1;
    }
    SmartPointer(SmartPointer<T> &sptr)
    {
        ref = sptr.ref;
        ref_count = sptr.ref_count;
        ++ (*ref_count);
    }
    SmartPointer<T>& operator=(SmartPointer<T> &sptr)
    {
        if(this != &sptr)
        {
            // if this point is just initialized (*ref_count = 1)
            if(--(*ref_count) == 0)
            {
                clear(); // clear its original pointing
                cout << "operator= clear" << endl;
            }
            ref = sptr.ref;
            ref_count = sptr.ref_count;
            ++*ref_count;
        }
        return *this;
    }
    ~SmartPointer()
    {
        // only re_count == 1 can be deleted, what if > 1?
        if(--*ref_count == 0)
        {
            clear();
            cout << "destructor clear" << endl;
        }
    }
    T getValue() { return *ref; }
};

int main()
{
    int *ip1 = new int();
    *ip1 = 11111;
    int *ip2 = new int();
    *ip2 = 22222;
    SmartPointer<int> sp1(ip1), sp2(ip2);
    SmartPointer<int> spa = sp1;
    sp2 = spa; // sp2's original space should be deleted
    return 0;
}
