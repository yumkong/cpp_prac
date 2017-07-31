# reshape a matrix
class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        row = len(nums)
        col = len(nums[0])
        # reshape size prod != original size prod, return original matrix
        if row * col != r * c or (row == r and col == c):
            return nums
        # concat orginal matrix row-wisely into a long row list
        long_list = []
        for i in range(row):
            long_list += nums[i]
        res = []
        for i in range(r):
            res.append(long_list[i * c : (i+1)*c])
        return res

if __name__ == '__main__':
    solu = Solution()
    print solu.matrixReshape([[1,2],[5,56]], 1,4)
