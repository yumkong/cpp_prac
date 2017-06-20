#include <iostream>
#include <vector>
#include <algorithm> //sort
using namespace std;

//T::value_type ==> container's value_type, e.g.: for vector<int>, it is int
template <typename T>
typename T::value_type mostFre(T first, T last)
{
    // compute memory size 
    std::size_t amount = 0;
    T start = first;
    while(start != last)
    {
        ++amount;
        ++start;
    }
    //alias of a vector<value_type>
    typedef vector<typename T::value_type> vecType;
    // create vector obj, save the input array's copy
    vecType vec(amount); //a vector of lenght of amount
    typename vecType::iterator newFirst = vec.begin();
    typename vecType::iterator newLast = vec.end();
    // copy input array to vec
    std::uninitialized_copy(first, last, newFirst);
    // sort to make same val appearing in neighboring positions
    std::sort(newFirst, newLast);
    
    //max val's occurence times, current val's occurence times
    std::size_t maxOccu = 0, occu = 0;
    typename vecType::iterator preIter = newFirst;
    typename vecType::iterator maxOccuEltIt = newFirst;
    while(newFirst != newLast)
    {
        if(*newFirst != *preIter)
        {
            if(occu > maxOccu)
            {
                maxOccu = occu;
                maxOccuEltIt = preIter;
            }
            occu = 0;
        }
        ++occu;
        preIter = newFirst;
        ++newFirst;
    }
    // remember to compare the occu times of the last val
    if(occu > maxOccu)
    {
        maxOccu = occu;
        maxOccuEltIt = preIter;
    }
    return *maxOccuEltIt;
}

int main()
{
    //later we should try more types. Here I only use array
    int arr[] = {66, 56, 3, 2, 1, 8, 993, 901, 8911, 67, 67, 54, 66, 21, 66};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    cout << "Most occurence integer is " << mostFre(vec.begin(), vec.end()) << endl;
    return 0;
}
