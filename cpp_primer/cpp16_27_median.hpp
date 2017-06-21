//search for the median val of a vector of unknown type
#ifndef MEDIAN_H
#define MEDIAN_H
#include <vector>
#include <algorithm> //sort
using namespace std;

//if vector has median, return true and record the median to the 2nd args
// otherwise, return false
template <typename T>
bool median(const vector<T>&, T&);

//introduce template's implementation file
#include "cpp16_27_median.cpp"
#endif 
