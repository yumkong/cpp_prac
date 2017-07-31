# reverse an integer
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        max_int32 = 2147483647;
        min_int32 = -2147483648;
        sign = 1
        if x < 0:
            sign = -1
        xabs = x * sign
        res = 0
        #NOT need to check the final digit (= 1st digit of input: always <= 2)
        while xabs > 0:
            # if larger than max or lower than min,return 0
            if res > max_int32 / 10 or res < min_int32 / 10:
                return 0
            res = res * 10 + xabs % 10
            xabs = xabs / 10
        return sign * res

if __name__ == '__main__':
    solu = Solution()
    print solu.reverse(1534236469)
    print solu.reverse(-1345679)
    print solu.reverse(-534236469) 
