#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;

vvi get_subsets(int a[], int n)
{
    vvi subsets;
    int max = 1 << n; // max number of subset
    for(int i = 0; i < max; ++i)
    {
        vi subset;
        int idx = 0;
        int j = i;
        while(j > 0)
        {
            if(j & 1) subset.push_back(a[idx]);
            j >>= 1; // fix bug: previous is : j >> 1;
            ++idx;
        }
        subsets.push_back(subset);
    }
    return subsets;
}

vvi get_subset_recursive(int a[], int idx, int n)
{
    vvi subsets;
    if(idx == n) // index come out of maximal elmt num
    {  
        vi subset; // empty set
        subsets.push_back(subset);
    }
    else
    {
        vvi rsubsets = get_subset_recursive(a, idx + 1, n); // idx = 2, 1, 0
        int v = a[idx];// 3, 2, 1
        for(int i = 0; i < rsubsets.size(); ++i)
        {
            vi subset = rsubsets[i];// {}
            subsets.push_back(subset);// {{}, }
            subset.push_back(v); // {3}, {2}
            subsets.push_back(subset);  // {{}, {3}}, {{}, {2}, {3}, {3, 2}}, {{}, {1}, {2}, {2,1}, {3}, {3,1},{3,2}, {3,2,1}}}
        }
    }   
    return subsets;
}

void print_subsets(vvi subsets)
{
    // 0622: both for loops are ok
    //for(typename vvi::size_type i = 0; i < subsets.size(); ++i)
    for(int i = 0; i < subsets.size(); ++i)
    {
        vi subset = subsets[i];
        //for(typename vi::size_type j = 0; j < subset.size(); ++j)
        for(int j = 0; j < subset.size(); ++j)
        { cout << subset[j] << " "; }
        cout << endl;
    }
}

int main()
{
    int a[] = {1,2,3};
    vvi sub = get_subsets(a, 3);
    print_subsets(sub);
    cout << "Recursive method: " << endl;
    vvi sub1 = get_subset_recursive(a, 0, 3);
    print_subsets(sub1);
    return 0;
}
