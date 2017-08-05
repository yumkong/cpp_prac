# count the number of triplets from the array that can make triangles 
class Solution(object):
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        leng = len(nums)
        if leng < 3:
            return 0
        nums.sort() # in ascending order
        cnt = 0
        for k in range(leng-1, 1, -1):
            i = 0
            j = k - 1
            # guarantee that the middle edge and short edge are different and their combine is unique
            while i < j:
                # if as small as i is ok, then all i till j-1 is ok (total j-1-i+1)
                if nums[i] + nums[j] > nums[k]:
                    cnt += j - i
                    j -= 1 # decreasing the middle edge anchor
                else:
                    i += 1
        return cnt

if __name__ == '__main__':
    solu = Solution()
    print solu.triangleNumber([2,2,2,3,4])
