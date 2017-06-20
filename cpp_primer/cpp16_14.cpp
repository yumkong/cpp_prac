#include <iostream>
#include <string>
#include <vector>
using namespace std;

//NOTE: for container not supporting subscript operation, cannot use this func
template <typename T> //T example vector<int>::iterator
void printContainerElt(T first, T last)
{
    
    for(; first != last; ++first)
    {
        cout << *first << ' ';
    }
    cout << endl;
}

int main()
{
    int iarr[] = {1,2,3,4,5,12,66};
    string sarr[] = {"Anna", "Mary", "William", "Tel", "Dave"};
    vector<int> ivec(iarr, iarr + 7);
    vector<string> svec(sarr, sarr + 5);
    printContainerElt(ivec.begin(), ivec.end());
    printContainerElt(svec.begin(), svec.end());

    return 0;
}
