//implementation of the template's func
template <typename T>
bool median(const vector<T>& c, T& m)
{
    // construct a copy for later sort
    vector<T> temp(c);
    // if vector contains even number of elts, no median
    if(temp.size() % 2 == 0)
    {
        return false;
    }
    //sort vec
    sort(temp.begin(), temp.end());
    //check whether the val in the middle is median value, if yes, record it in m and return true
    typename vector<T>::size_type index = temp.size() / 2;
    if(temp[index] > temp[index - 1] && temp[index] < temp[index + 1])
    {
        m = temp[index];
        return true;
    }
    else
    {
        return false;
    }
}
