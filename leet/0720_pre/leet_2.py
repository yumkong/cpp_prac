# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        res = None
        carry = 0
        while(l1 is not None and l2 is not None):
            sum1 = l1.val + l2.val + carry
            carry = sum1 / 10
            sum1 = sum1 % 10
            q = ListNode(sum1)
            if(res is not None):
                p.next = q  #reference assignment
            else:
                res = q   #reference assignment
            p = q  #reference assign
            l1 = l1.next
            l2 = l2.next
        if(l1 is not None):
            remainList = l1
        else:
            remainList = l2
        while(remainList is not None):
            sum1 = remainList.val + carry
            carry = sum1 / 10
            sum1 = sum1 % 10
            q = ListNode(sum1)
            if(res is not None):
                p.next = q
            else:
                res = q
            p = q
            remainList = remainList.next
        if(carry > 0):
            q = ListNode(1)
            if(res is not None):
                p.next = q
            else:
                res = q
        return res

if __name__ == '__main__':
    lst1 = [1,2,3,4,9]
    lst2 = [1, 3, 8]
    l1 = None
    l2 = None
    for i in range(len(lst1)):
        tmp = ListNode(lst1[i])
        if l1 is None:
            l1 = tmp
        else:
            p.next = tmp
        p = tmp
    for i in range(len(lst2)):
        tmp = ListNode(lst2[i])
        if l2 is None:
            l2 = tmp
        else:
            p.next = tmp
        p = tmp
    
    solu = Solution()
    res = solu.addTwoNumbers(l1, l2)
    tmp = res
    while(tmp is not None):
        print tmp.val
        tmp = tmp.next

