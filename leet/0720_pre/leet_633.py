# check whether an integer z is a sum of two squares: z = x^2 + y^2
import math
class Solution(object):
    def judgeSquareSum(self, c):
        '''
        :type c: int
        :rtype: bool
        '''
        mid = int(math.sqrt(c))
        found = False
        for i in range(mid, -1, -1):
            if isSquareNum(c - i * i):
                found = True
                break
        return found

def isSquareNum(n):
    '''
    :type n: int
    :rtype: bool
    '''
    tmp = int(math.sqrt(n))
    return (n == tmp * tmp)

if __name__ == '__main__':
    solu = Solution()
    print solu.judgeSquareSum(3) 
