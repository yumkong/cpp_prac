# flowers cannot be placed in adjcent positions
# according to this rule, can the specified number of flowers be sufficiently placed 
# in empty positions (with number of 0)
class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        leng = len(flowerbed)
        if leng == 1:
            return n == 0 or (flowerbed[0] == 0 and n <= 1)
        if leng == 2:
            return n == 0 or (flowerbed[0] == 0 and flowerbed[1] == 0 and n <= 1)
        # cnt_local: how many consecutive valid pos
        cnt = 0
        cnt_local = 0
        if flowerbed[0] == 0:
            cnt_local = 2
        for i in range(1, leng):
            if flowerbed[i] == 0:
                cnt_local += 1
            else: #when obstacle occurs check out the cnt_local into cnt (total nums)
                if cnt_local > 0:
                    cnt += (cnt_local - 1) / 2
                    cnt_local = 0
        if flowerbed[leng - 1] == 0:
            cnt_local += 1
        if cnt_local > 0:
            cnt += (cnt_local - 1) / 2
        return cnt >= n

if __name__ == '__main__':
    solu = Solution()
    print solu.canPlaceFlowers([1, 0, 0, 0, 1], 1)
