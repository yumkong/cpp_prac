# find the shortest unsorted continuous subarray
class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_int = 2147483647
        min_int = -2147483648
        leng = len(nums)
        if leng == 1:
            return 0
        if leng == 2:
            return int(nums[0] > nums[1]) * 2 
        left = 0
        right = 0
        # check left border
        for i in range(leng - 1):
            if nums[i] <= nums[i+1]:
                left += 1
            else:
                break
        if left == leng - 1:
            return 0
        # check right border: from [leng-1] to [1]
        for i in range(leng - 1, 0, -1):
            if nums[i] >= nums[i-1]:
                right += 1
            else:
                break
        # get min and max in the unsorted region
        min_pos = max_int
        max_pos = min_int
        for i in range(left, leng - right, 1):
            if min_pos > nums[i]:
                min_pos = nums[i]
            if max_pos < nums[i]:
                max_pos = nums[i]
        # initial unsorted length
        unsort_len = leng - left - right
        for i in range(left - 1, -1, -1):
            if nums[i] > min_pos:
                unsort_len += 1
            else:
                break
        for i in range(leng - right, leng, 1):
            if nums[i] < max_pos:
                unsort_len += 1
            else:
                break
        return unsort_len

if __name__ == '__main__':
    solu = Solution()
    print solu.findUnsortedSubarray([2, 6, 5, 9, 15])
