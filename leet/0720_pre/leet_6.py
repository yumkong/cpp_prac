#zigzag coversion of a string
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        leng = len(s)
        if leng <= 2 or numRows == 1:
            return s
        # length of a single repeatable pattern
        onelen = 2 * numRows - 2
        #e.g when numRows = 4, rowidx = [0 1 2 3 2 1]
        rowidx = range(numRows) # [0 1 2 3]
        for i in range(numRows, onelen):
            rowidx.append(numRows - 2 - (i % numRows))
        reslst = [''] * numRows #numRow empty lists, each storing one row of chars
        #
        for i in range(leng):
            reslst[rowidx[i % onelen]] += s[i]
        # concat into a single str
        res = '' #empty str
        for i in range(numRows):
            res += reslst[i]
        return res

if __name__ == '__main__':
    solu = Solution()
    print solu.convert("PAYPALISHIRING", 3)
        
