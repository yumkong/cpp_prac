#include <iostream>
#include <string>
#include <vector>
using namespace std;

//NOTE: for container not supporting subscript operation, cannot use this func
template <typename T> //T example vector<int>
void printContainerElt(T& ct)
{
    typename T::size_type iter;
    for(iter = 0; iter != ct.size(); ++iter)
    {
        cout << ct[iter] << ' ';
    }
    cout << endl;
}

template <typename T>
void printContainerElt2(const T& ct)
{
    typename T::const_iterator iter;
    for(iter = ct.begin(); iter != ct.end(); ++iter)
    {
        cout << *iter << ' ';
    }
    cout << endl;
}

int main()
{
    int iarr[] = {1,2,3,4,5,12,66};
    string sarr[] = {"Anna", "Mary", "William", "Tel", "Dave"};
    vector<int> ivec(iarr, iarr + 7);
    vector<string> svec(sarr, sarr + 5);
    cout << "Result 1: " << endl;
    printContainerElt(ivec);
    printContainerElt(svec);
    cout << "Result 2: " << endl;
    printContainerElt2(ivec);
    printContainerElt2(svec);

    return 0;
}
