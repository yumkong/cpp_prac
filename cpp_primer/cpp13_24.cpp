// countable HasPtr class
#include <iostream>
using namespace std;

// use-counted U_Ptr class
class U_Ptr
{
private:
    friend class HasPtr;
    int *ip;
    size_t use;
    U_Ptr(int *p): ip(p), use(1) {}
    // 
    ~U_Ptr() { 
    cout << "~U_Ptr(): *ip = " << *ip  << ", ip = " << ip <<  endl;
    delete ip; }
};

// HasPtr class
class HasPtr
{
private:
    // points to use-counted U_Ptr class
    U_Ptr *ptr;
    int val;
public:
    // constructor: points to already dynamically created int pointer
    HasPtr(int *p, int i): ptr(new U_Ptr(p)), val(i) { }
    // copy constructor: copy and use+1
    HasPtr(const HasPtr &orig): ptr(orig.ptr), val(orig.val) {++ptr->use;}
    // assign operator
    HasPtr& operator=(const HasPtr &);
    // destructor: reduce use count by 1, but only delete it when count reduced to 0
    ~HasPtr() 
    {
        cout << "~HasPtr()" << endl;
        if(--ptr->use == 0) delete ptr;
    }
    // get member val
    int *get_ptr() const {return ptr->ip; }
    int get_int() const {return val; }
    // set member val
    void set_ptr(int *p) {ptr->ip = p;}
    void set_int(int i)  {val = i; }
    // return or set basic int obj
    int get_ptr_val() const { return *ptr->ip; }
    int set_ptr_val(int i) { *ptr->ip  = i; }
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    // increase rhs's use count
    ++rhs.ptr->use;
    // reduce lhs's use count by 1
    // if 0, delete U_Ptr obj
    if(--ptr->use == 0) delete ptr;
    ptr = rhs.ptr;
    val = rhs.val;
    return *this;
}

int main()
{
    // note that if not "delete p", the data pointed by p always exist even after main
    // if here use "int p = 42" and "HasPtr(&p, 6)" ==> cause segmentation fault because main() will automatically    // release p, even before the calling of ~U_Ptr
    int *p = new int(42);
    //p = &q;
    HasPtr p1(p, 6);
    HasPtr p2 = p1;
    // 8 6
    cout << p2.get_ptr_val() << endl;
    p1.set_ptr_val(666);
    cout << p2.get_ptr_val() << endl;
    return 0;
}

