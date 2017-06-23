#include <iostream>
using namespace std;

// O(m + n) : the total time is to decrease k from (n+m-1) to (0) ==> m + n
void merge(int a[], int b[], int n, int m)
{
    // last elm idx of all
    int k = n + m - 1;
    // i = last elm idx of a, j = last elm idx of b
    int i = n - 1, j = m - 1;
    while(i >= 0 && j >= 0)
    {
        //whicheve is large is attached to the end
        // so each time the end index decreases by one
        // and index of larger elem of (a or b) decreases by 1
        // but index of smaller one not change, directly go to next comparison
        if(a[i] > b[j]) a[k--] = a[i--];
        else a[k--] = b[j--];
    }
    //if b still have elems, then they are smaller than all a's elements
    // put them to the top
    while(j >= 0)
    {
        a[k--] = b[j--];
    }
}

int main()
{
    int a[15] = {1, 3, 5, 7, 9, 10};
    int b[] = {2, 4, 6, 8, 12};
    int n = 6, m = 5;
    merge(a, b, n, m); 
    for(int i = 0; i < m + n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
