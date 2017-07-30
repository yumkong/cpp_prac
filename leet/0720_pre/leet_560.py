# find total number of continous subarrays whose sum is k
class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        leng = len(nums)
        sum_cnt = dict()
        # 0 is natural sum factor
        sum_cnt[0] = 1
        sum_tmp = 0
        cnt = 0
        for i in range(leng):
            # integral (sum) from [0] to [i]
            sum_tmp += nums[i]
            if sum_cnt.has_key(sum_tmp - k):
                 cnt += sum_cnt[sum_tmp - k]
            if sum_cnt.has_key(sum_tmp):
                 sum_cnt[sum_tmp] += 1
            else:
               sum_cnt[sum_tmp] = 1
        return cnt

if __name__ == '__main__':
    solu = Solution()
    print solu.subarraySum([1,1,1], 2) 
