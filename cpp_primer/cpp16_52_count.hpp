// this file is for 16.52, 16.53 and 16.54
#ifndef CPP16_52_COUNT_H
#define CPP16_52_COUNT_H

#include <iostream>
#include <vector>
//#include <algorithm>
#include <string>
#include <cstddef>
#include <algorithm>
//using namespace std;
using std::vector;
using std::string;
using std::size_t;

// count the occurence number of some values (stored in sought) in vec
template <typename T>
size_t count(const vector<T> &vec, const vector<T> &sought)
{
    size_t result = 0;
    for(typename vector<T>::const_iterator iter = sought.begin(); iter != sought.end(); ++iter)
    {
        result += std::count(vec.begin(), vec.end(), *iter);
    }
    return result;
}

//16.54
// template specialization
// this is only for illustration, the above alrealy constains this case
template <>
size_t count<string>(const vector<string> &vec, const vector<string> &sought)
{
    std::cout << "Using template specialization" << std::endl;
    size_t result = 0;
    for(vector<string>::const_iterator iter = sought.begin(); iter != sought.end(); ++iter)
    {
        result += std::count(vec.begin(), vec.end(), *iter);
    }
    return result;
}

#endif
