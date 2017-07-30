# given an integer array and an integer k, find number of unique k-diff pairs in array.
# k-diff pair e.g.: (i, j) where |i-j| == k
class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k < 0:
            return 0
        # sort input array in ascending order
        nums.sort()
        leng = len(nums)
        cnt = 0
        diff_cnt = dict()
        if k > 0:
            for i in range(leng):
                if diff_cnt.has_key(nums[i]):
                    diff_cnt[nums[i]] += 1
                else:
                    diff_cnt[nums[i]] = 1
                if diff_cnt[nums[i]] == 1 and diff_cnt.has_key(nums[i] - k):
                    cnt += 1
        else: # k == 0
            for i in range(leng):
                if diff_cnt.has_key(nums[i]):
                    diff_cnt[nums[i]] += 1
                else:
                    diff_cnt[nums[i]] = 1
                if diff_cnt[nums[i]] == 2:
                    cnt += 1
        return cnt

if __name__ == '__main__':
    solu = Solution()
    l1 = [1,1,1,1,1]
    l2 = [3,1,4,1,5]
    l3 = [1,2,3,4,5]
    l4 = [1,3,1,5,4]
    l5 = [1,1,1,2,2]
    print solu.findPairs(l1, 0)
    print solu.findPairs(l2, 2)
    print solu.findPairs(l3, 1)
    print solu.findPairs(l4, 0)
    print solu.findPairs(l5, 1)
