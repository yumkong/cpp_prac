// median of two sorted arrays
#include <vector>
#include <iostream>
using namespace std;
// change to find the k-th element in two sorted arrays
class Solution {
public:
  
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        // both empty
        if (len1 == 0 && len2 == 0) return 0.0;
        if( (len1 + len2) % 2 == 0)
        {
            //cout << "here1" << endl;
            return (GetKth(nums1.begin(), len1, nums2.begin(), len2, (len1+len2)/2-1) + GetKth(nums1.begin(), len1, nums2.begin(), len2, (len1+len2)/2))/2.0; // the k-th and (k+1)-th => actual indices should be  [k-1], [k]
        } 
        else
        {
            //cout << "here2" << endl;
            return GetKth(nums1.begin(), len1, nums2.begin(), len2, (len1 + len2)/2); // the k-th elem, actual index is [k].
        }
    }
    int GetKth (vector<int>::iterator A, int alen, vector<int>::iterator B, int blen, int k)
    {
        //assert(!A.empty() && !B.empty())
        // liu@0705: NOTE when stoping iteration, should turn the k-th elememnt to actual index [k-1]
        //if(alen <= 0) return *(B + min(k, blen-1)); // if A is empty, return B[k-1]
        //if(blen <= 0) return *(A + min(k, alen-1)); // if B is empty, return A[k-1]
		if(alen <= 0) return *(B + k); // if A is empty, return B[k-1]
        if(blen <= 0) return *(A + k); // if B is empty, return A[k-1]
        if(k <= 0) return min(*A, *B);   // return the 1st element of two
		if(alen==1 && blen ==1 ) return max(*A, *B); // k must be 1
		// 
		int bmid = (blen % 2 == 0) ? (blen / 2 - 1): blen / 2;
		int amid = (alen % 2 == 0) ? (alen / 2 - 1): alen / 2;
        //if(*(B + blen / 2) >= *(A + alen / 2))
		if(*(B + bmid) >= *(A + amid))
        {  
            // the middle point is in the first half, delete the bigger B's last half
            //if((alen + blen)/2 > k) 
			//if(amid + bmid + 1 == k) 
			//{	
			//    return *(B + bmid);
		    //}
			if(amid + bmid + 1 >= k) //(amid + 1)+(bmid + 1) - 1 = amid+bmid+1 is the joint idx of two arrays
            {
                //cout << "here3, k = " << k << endl;
                //return GetKth(A, alen, B, blen / 2, k); // still find the first kth element
				//add a special case:
				//if(blen == 1) return *(A + k-1);
				//int blen_new = min(blen - 1, bmid + 1);
				if(blen == 1 && *(B+bmid)<*(A+alen-1)) //compare with A's last element
				{
					return GetKth(A, alen-1, B, blen, k);
				}
				else if(blen == 1)
				{
					return GetKth(A, alen, B, bmid, k);// extreme situation not plus 1
				}
				else{
					return GetKth(A, alen, B, bmid+1, k); // normal situation bmid+1, because *(B + bmid) is "bmid+1"th term
				}
            }
            else // the mid point is in the second half, delele the smaller A's first half
            {
                //cout << "here4, k = " << k << endl;
                //return GetKth(A + alen/2 + 1, alen - (alen/2+1), B, blen, k - (alen/2+1));
				return GetKth(A + amid + 1, alen - (amid+1), B, blen, k - (amid+1));
            }
        }
        else
        { 
            // the middle point is in the first half, delete the bigger A's last half
            //if((alen + blen)/2 > k)
			//if(amid + bmid + 1 == k) 
			//{	
			//    return *(A + amid);
		    //}
            if(amid + bmid + 1 >= k) 
			{
                //cout << "here5, k = " << k << endl;
                //return GetKth(A, alen/2, B, blen, k); // still find the first kth element
				//return GetKth(A, min(amid + 1, alen - 1), B, blen, k); 
				if(alen == 1 && *(A+amid)<*(B+blen-1))
				{
					return GetKth(A, alen, B, blen-1, k);
				}
				else if(alen == 1)
				{
					return GetKth(A, amid, B, blen, k);
				}
				else{
					return GetKth(A, amid+1, B, blen, k);
				}
            }
            else // the mid point is in the second half, delele the smaller B's first half
            {
                //cout << "here6, k = " << k << endl;
                //return GetKth(A, alen, B + blen/2+1, blen - (blen/2+1), k - (blen/2+1));
				return GetKth(A, alen, B + bmid + 1, blen - (bmid + 1), k - (bmid + 1));
            }
        }
    }
};

int main()
{
    Solution solu;
    int a[] = {1,3,5};
    int b[] = {2,4};
    vector<int> avec(a, a+sizeof(a)/sizeof(a[0]));
    vector<int> bvec(b, b+sizeof(b)/sizeof(b[0]));
    cout << "Median = " << solu.findMedianSortedArrays(avec, bvec) << endl;
    return 0;
}
