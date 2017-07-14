class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        lst = []
        mydict = dict()
        cnt = 0
        for i in nums:
            if not mydict.has_key(i):
                mydict[target - i] = cnt
                cnt += 1
            else:
                lst.append(mydict[i])
                lst.append(cnt)
                break
        return lst

if __name__ == '__main__':
    solu = Solution()
    print solu.twoSum([1,2,3,9,8,6], 10)
