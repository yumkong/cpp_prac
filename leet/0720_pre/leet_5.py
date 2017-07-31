#find the longest palindromic substring given a string s (maxlen = 1000)
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        leng = len(s)
        if leng <= 1:
            return s
        longeststr = ""
        for i in range(leng - 1):
            tmpstr = findPalindrome(s, i, i)
            if len(tmpstr) > len(longeststr):
                longeststr = tmpstr
            tmpstr = findPalindrome(s, i, i+1)
            if len(tmpstr) > len(longeststr):
                longeststr = tmpstr
        return longeststr
   
    def longestPalindrome_dp(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        if n <= 1:
            return s
        start = 0
        leng = 1 #at least the 1st element of a string is a palin
        matrix = []
        for i in range(n):
            lst = [False] * (i+1) # a list of i+1 False
            matrix.append(lst)
            matrix[i][i] = True
            for j in range(i):
                if j == i or (s[j] == s[i] and (i - j < 2 or matrix[i-1][j+1])):
                    matrix[i][j] = True
                    #update current palindrome
                    if leng < i - j + 1:
                        start = j
                        leng = i - j + 1
        return s[start: start + leng]

def findPalindrome(s, left, right):
    leng = len(s)
    while left >= 0 and right <= leng - 1 and s[left] == s[right]:
        left -= 1
        right += 1
    return s[left + 1 : right] #[left+1, right-1]



if __name__ == '__main__':
    solu = Solution()
    print solu.longestPalindrome("swsaabacdfgfdcabaxyz")
    print solu.longestPalindrome_dp("swsaabacdfgfdcabaxyz")
