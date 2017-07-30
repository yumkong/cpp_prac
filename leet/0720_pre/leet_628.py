#given an integer array, find 3 numbers whose product is maximum and output this maximum product
class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_int = 2147483647
        min_int = -2147483648
        leng = len(nums)
        if leng == 3:
            return nums[0] * nums[1] * nums[2]
        max1 = min_int # 1st
        max2 = min_int # 2nd
        max3 = min_int # 3rd
        min1 = max_int # last
        min2 = max_int # 2nd last
        for i in range(leng):
            # calc the three max
            if nums[i] > max1:
                max3 = max2
                max2 = max1
                max1 = nums[i]
            elif nums[i] > max2:
                max3 = max2
                max2 = nums[i]
            elif nums[i] > max3:
                max3 = nums[i]
            # calc the two min: should be independent to calu max (min and max could be duplicate when leng <=5?)
            if nums[i] < min1:
                min2 = min1
                min1 = nums[i]
            elif nums[i] < min2:
                min2 = nums[i]
        # if all are less or equal than 0
        if max1 <= 0:
            return max1 * max2 * max3
        else:
            if min1 * min2 > max2 * max3:
                return min1 * min2 * max1
            else:
                return max1 * max2 * max3
if __name__ == '__main__':
    solu = Solution()
    print solu.maximumProduct([2, 1, 2, 3])

