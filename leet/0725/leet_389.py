class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        leng = len(s)
        if(leng == 0):
            return t[0]
        s = sorted(s)
        t = sorted(t)
        for i in range(leng):
            if s[i] != t[i]:
                return t[i]
        return t[leng]

if __name__ == '__main__':
    solu = Solution()
    print solu.findTheDifference("abcd", "dcabe")
