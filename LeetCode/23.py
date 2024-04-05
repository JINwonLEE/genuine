# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def mergeTol1(l1, l2):
            if l1 == None:
                l1 = l2
                return
            if l2 == None:
                return
            prev1 = l1
            cur1 = l1
            cur2 = l2
            next2 = l2
            while cur1 != None and cur2 != None:
                if cur1.val >= cur2.val:
                    prev1.next = cur2
                    next2 = cur2.next
                    cur2.next = cur1
                    prev1 = prev1.next
                    cur2 = next2
                else:
                    prev1 = cur1
                    cur1 = cur1.next
            if cur2 != None:
                prev1.next = cur2
            return
        head = ListNode(-10001)
        for l in lists:
            mergeTol1(head, l)
        return head.next

