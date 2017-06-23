#include <iostream>
using namespace std;

// principle: at least half of the array is ordered
// principle: if else clause is O(1), what matters is how many times while is executed
//search(array, lowest idx, highest idx, number to be searched)
template <size_t N>
int search(int (&a)[N], int x)
{  
    // lowest idx, highest idx of array
    int low = 0, high = N - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(a[mid] == x) return mid;
        // from [low, mid], in ascending order
        if(a[mid] >= a[low])
        {
            // if a is in between, if must lies in the range of [low, mid]
            if(x < a[mid] && x >= a[low])
            {
                high = mid - 1;
            }
            else 
            {
                low = mid + 1;
            }
        }
        else // from [mid, high] must in ascending order
        {
            if(x <= a[high] && x > a[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

}

int main()
{
    int a[] = {15, 16, 19, 20, 26, 1, 3, 4, 5, 6, 6, 6, 12, 14};
    cout << search(a, 6) << endl;
    return 0;
}
