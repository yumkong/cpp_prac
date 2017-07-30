#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if(len == 1) return (flowerbed[0] == 0 && n <= 1) || (n == 0);
        if(len == 2) return (flowerbed[0] == 0 && flowerbed[1] == 0 && n <= 1) || (n == 0);
        // cnt total valid, cnt_local: how many consecutive valid pos
        int cnt = 0, cnt_local = 0;
        if(flowerbed[0] == 0) cnt_local = 2; 
        for(int i = 1; i < len; ++i)
        {
            if(flowerbed[i] == 0)
            {
                ++cnt_local;
            }
            else
            {   // 1
                if(cnt_local > 0) cnt += (cnt_local - 1)/2;
                cnt_local = 0;
            }
        }
        if(flowerbed[len - 1] == 0) ++cnt_local;
        if(cnt_local > 0) cnt += (cnt_local - 1)/2;
        return (cnt >= n);
    }
};

int main()
{
    int a[] = {1, 0, 0, 0, 1};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.canPlaceFlowers(arr, 1) << endl;
    return 0;
}
