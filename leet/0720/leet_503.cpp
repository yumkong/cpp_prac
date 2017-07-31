#include <map>
#include <stack>
#include <iostream>
#include <utility> // make_pair(func), pair (class)
#include <vector>
using namespace std;

class Solution {
public:
    // premise: all elements in findNums and nums are unique
    vector<int> nextGreaterElement(vector<int>& nums) {
        int len = nums.size();
        stack<int> valstack;
        stack<int> idxstack;
        vector<int> res(len, -1); // initialize all as -1
        int maxval = (1 << 31); // intialize as min_int32
        int tmpidx;
        for(int i = 0; i < len; ++i)
        {
            while(!valstack.empty() && valstack.top() < nums[i])
            {
                tmpidx = idxstack.top(); // get the index stack top
                idxstack.pop();  // pop the index stack top
                //cout << "Poping out " << valstack.top() << endl;
                valstack.pop();  // pop the val stack top accordingly
                res[tmpidx] = nums[i]; // given the next great value to the stack top value
            }
            //cout << "Pushing in " << nums[i] << endl;
            valstack.push(nums[i]);  // now the elements in stack are all "large" and in descending order
            idxstack.push(i);  // push idx to stack accordingly
            if(maxval < nums[i])  maxval = nums[i]; // get max in the array
        }
        // check out next great value of each elem of the descending array in stack s[0], s[1], ...s[top]:
        for(int i = 0; i < len; ++i)
        {
            while(!valstack.empty() && valstack.top() < nums[i])
            {
                tmpidx = idxstack.top(); // get the index stack top
                idxstack.pop();  // pop the index stack top
                //cout << "Poping out " << valstack.top() << endl;
                valstack.pop();  // pop the val stack top accordingly
                res[tmpidx] = nums[i]; // given the next great value to the stack top value
            }
            //stopping criterion: meet the maxval
            if(valstack.top() == maxval || nums[i] == maxval) break;
        }
        return res;
    }
};

int main()
{
    int a1[] = {100,1,11,1,120,111,123,1,-1,-100};
    vector<int> arr1(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    Solution solu;
    vector<int> res = solu.nextGreaterElement(arr1);
    vector<int>::iterator it;
    for(it = res.begin(); it < res.end(); ++it)
    { cout << *it << " "; }
    cout << endl;
    return 0;
}
