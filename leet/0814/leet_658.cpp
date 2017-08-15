// binary search category:
// given a sorted array, two ints k and x, find the k closest elems to x in the array
// the result should be sorted in ascending order. If there is a tie, the smaller elements are used
// NOTE: (1) k is positive and always smaller than array length
//       (2) array length is positive and <= 10^4 
//       (3) x is not nessisarily in array
#include <iostream>
#include <vector>
#include <cmath> // abs
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();
        int left = 0, right = len - 1, mid;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(arr[mid] > x) right = mid - 1;
            else if(arr[mid] < x) left = mid + 1;
            else break; // mid the desired position
        }
        // update mid
        mid = (right <= left)? left: mid;
        // update the position where x first occurs
        while(mid >= 1 && arr[mid] == arr[mid - 1]) --mid;
        // reuse left and right to store the final starting and ending pos
        left = mid, right = mid;
        while(right - left + 1 < k)
        {
            if(left == 0) ++right;
            else if(right == len - 1) --left;
            else
            {   // if equal, prefer left
                if(abs(arr[left - 1] - x) <= abs(arr[right + 1] - x)) --left;
                else ++right;
            }
        }
        cout << "mid = " << mid << ", left = " << left << ", right = " << right << endl;
        vector<int> res(arr.begin() + left, arr.begin() + right + 1);
        return res;
    }
};

int main()
{
    //vector<int> input({1,2,3,4,5,6}); // k = 4, x = 3
    vector<int> input({0, 0, 0, 1, 3, 5, 6, 7, 8, 8});
    Solution solu;
    vector<int> res = solu.findClosestElements(input, 2, 2);
    for(auto& i: res) cout << i << " ";
    cout << endl;
    return 0;
}
