// a template function that can make sure an array's length
#include <iostream>
#include <string>
using namespace std;

//template <typename T, size_t N>
//size_t size(T (&arr)[N])
//{
//    return N;
//}

template <typename T, size_t N>
void printValues(T (&arr)[N])
{
    for(size_t i = 0; i < N; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int iarr[] = {1,2,3,4,5,12,66};
    string sarr[] = {"Anna", "Mary", "William", "Tel", "Dave"};
    //cout << "int array size: " << size(iarr) << endl;
    //cout << "str array size: " << size(sarr) << endl;
    printValues(iarr);
    printValues(sarr);
    return 0;
}
