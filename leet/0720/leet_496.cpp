#include <map>
#include <stack>
#include <iostream>
#include <utility> // make_pair(func), pair (class)
#include <vector>
using namespace std;

class Solution {
public:
    // premise: all elements in findNums and nums are unique
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int len = nums.size();
        map<int, int> cntmap; // store pairs: <elemnt, elemnt's next greater value>
        stack<int> istack;
        for(int i = 0; i < len; ++i)
        {
            while(!istack.empty() && istack.top() < nums[i])
            {
                cntmap.insert(make_pair(istack.top(), nums[i]));
                istack.pop();  // delete stack top's element but not return its value
            }
            istack.push(nums[i]);  // now the elements in stack are all "large" and in descending order
        }     
        vector<int> res;
        for(int i = 0; i < findNums.size(); ++i)
        {
            if(cntmap.count(findNums[i]))  // if this greater val exists
            {
                res.push_back(cntmap[findNums[i]]);
            }
            else
            {
                res.push_back(-1);
            }
        }
        return res;
    }
};

int main()
{
    int a1[] = {2,4};
    int a2[] = {1,2,3,4};
    vector<int> arr1(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    vector<int> arr2(a2, a2 + sizeof(a2)/sizeof(a2[0]));
    Solution solu;
    vector<int> res = solu.nextGreaterElement(arr1, arr2);
    vector<int>::iterator it;
    for(it = res.begin(); it < res.end(); ++it)
    { cout << *it << " "; }
    cout << endl;
    return 0;
}
