class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = dict()
        maxLen = 0
        lastRepeatPos = -1
        for i in range(len(s)):
            if d.has_key(s[i]) and lastRepeatPos < d[s[i]]:
                lastRepeatPos = d[s[i]]
            if i - lastRepeatPos > maxLen:
                maxLen = i - lastRepeatPos
            d[s[i]] = i
        return maxLen

if __name__ == "__main__":
    solu = Solution()
    s = "abcabcbb"
    print s + ": " + str(solu.lengthOfLongestSubstring(s))
    s = "bbbbb"
    print s + ": " + str(solu.lengthOfLongestSubstring(s))
    s = "bbabcdb"
    print s + ": " + str(solu.lengthOfLongestSubstring(s))
