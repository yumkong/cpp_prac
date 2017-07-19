# a zero-index array A consist of N different ints, with all elements in the range [0, N-1]
# return the size of the largest nest set S[K] = {A[k], A[A[k]], ...}
class Solution(object):
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        leng = len(nums)
        nest_cnt = dict()
        res = 0 #max length of nested set
        for i in range(leng):
            idx = i
            tmp_cnt = 0
            if nest_cnt.has_key(idx):
                nest_cnt[idx] += 1
            else:   
                nest_cnt[idx] = 1
            while nest_cnt.has_key(idx) and nest_cnt[idx] == 1:
                tmp_cnt += 1 #record the current set length
                idx = nums[idx]
                if nest_cnt.has_key(idx):
                    nest_cnt[idx] += 1
                else:
                    nest_cnt[idx] = 1
            # a position has been visited more than once
            if nest_cnt.has_key(idx) and nest_cnt[idx] > 1:
                nest_cnt[idx] -= 1
                # only for the 1st time visited set (tmp_cnt > 0)
                if tmp_cnt > 0 and res < tmp_cnt:
                    res = tmp_cnt
                    tmp_cnt = 0
        return res

if __name__ == '__main__':
    solu = Solution()
    print solu.arrayNesting([5,4,0,3,1,6,2])
