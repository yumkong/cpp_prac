class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        len1 = len(nums1)
        len2 = len(nums2)
        if len1 == 0 and len2 == 0:
            return 0.0
        if (len1 + len2)%2 == 0:
            return (GetKth(nums1, len1, nums2, len2, (len1 + len2)/2 - 1) + \
                   GetKth(nums1, len1, nums2, len2, (len1 + len2)/2)) / 2.0
        else:
            return GetKth(nums1, len1, nums2, len2, (len1 + len2)/2)
def GetKth(A, alen, B, blen, k):
        if alen <= 0:
            return B[k]
        if blen <= 0:
            return A[k]
        if k <= 0:
            return min(A[0], B[0])
        if (alen == 1) and (blen == 1):
            return max(A[0], B[0])
        #if even numbers, return the idx of the first half's last element
        #if odd, return the idx of middle element
        # equivalent to C/C++: (alen % 2) == 0 ? (alen / 2 - 1): (alen / 2)
        amid = (alen / 2 - 1) if (alen % 2 == 0) else (alen / 2)
        bmid = (blen / 2 - 1) if (blen % 2 == 0) else (blen / 2)
        if B[bmid] >= A[amid]:
            if amid + bmid + 1 >= k:
                # if B has only 1 elem, compare B with A's last element, whichever larger is deleted
                if blen == 1:
                    if B[bmid] < A[alen - 1]:
                        return GetKth(A, alen - 1, B, blen, k)
                    else:
                        return GetKth(A, alen, B, bmid, k)
                else:
                    #if B has >= 2 elems, keep the first half(even) or half+1 (odd) element
                    return GetKth(A, alen, B, bmid + 1, k)
            else:
                # discard the 1st amid+1 elems
                return GetKth(A[amid+1:], alen - (amid+1), B, blen, k - (amid+1))
        else:
            if amid + bmid + 1 >= k:
                # if B has only 1 elem, compare B with A's last element, whichever larger is deleted
                if alen == 1: 
                    if A[amid] < B[blen - 1]:
                        return GetKth(A, alen, B, blen-1, k)
                    else:
                        return GetKth(A, amid, B, blen, k)
                else:
                    #if B has >= 2 elems, keep the first half(even) or half+1 (odd) element
                    return GetKth(A, amid+1, B, blen, k)
            else:
                # discard the 1st amid+1 elems
                return GetKth(A, alen, B[bmid+1:], blen - (bmid+1), k - (bmid+1))

if __name__ == '__main__':
    solu = Solution()
    l1 = [1,4]
    l2 = [3]
    print solu.findMedianSortedArrays(l1, l2)
