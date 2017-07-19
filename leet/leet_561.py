#given an array of 2n ints, group these integers into n pairs which makes sum of pair_i for all i 
#from 1 to n as large as possible
class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        leng = len(nums)
        nums.sort()
        res = 0
        for i in range(0, leng, 2):
            res += nums[i]
        return res

if __name__ == '__main__':
    solu = Solution()
    print solu.arrayPairSum([1,4,3,2])

