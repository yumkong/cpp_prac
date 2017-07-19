#determine whether an integer is a palindrome
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0 or (x > 0 and x % 10 == 0):
            return False
        if x < 10:
            return True
        reverse_x = 0
        while reverse_x < x:
            reverse_x = reverse_x * 10 + (x % 10)
            x = x / 10
        return (x == reverse_x) or (x == reverse_x / 10)

if __name__ == '__main__':
    solu = Solution()
    print solu.isPalindrome(12321)
    print solu.isPalindrome(1231)
    print solu.isPalindrome(1221)
