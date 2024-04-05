# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head
        left = head
        cur = head.next
        ans = cur
        while cur != None:
            if cur.next == None:
                cur.next = left
                left.next = None
                break
            right = cur.next
            cur.next = left
            if right.next == None:
                left.next = right
            else:
                left.next = right.next
            left = right
            cur = right.next
        return ans
