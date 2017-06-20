#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename It, typename T>
It findElt(It first, It last, const T& val)
{
    while(first != last)
    {
        if(*first == val) return first;
        ++first;
    }
    return last;
}

int main()
{
    int iarr[] = {1, 2, 3, 4, 5, 6, 7};
    string sarr[] = {"William", "Mary", "George", "Washington", "Ted", "test"};
    vector<int> ivec(iarr, iarr + 7);
    vector<string> svec(sarr, sarr + 6);

    vector<int>::iterator iit;
    if((iit = findElt(ivec.begin(), ivec.end(), 66)) != ivec.end())
    {
        cout << "found element " << *iit << endl;
    }
    else
    {
        cout << "no such element" << endl;
    }

    vector<string>::iterator sit;
    if((sit = findElt(svec.begin(), svec.end(), "Ted")) != svec.end())
    {
        cout << "found element " << *sit << endl;
    }
    else
    {
        cout << "no such element" << endl;
    }

    return 0;
}
