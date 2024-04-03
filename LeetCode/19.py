# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        l = 0
        cur = head
        while cur != None:
            l += 1
            cur = cur.next
        ind = l - n
        cur = head
        prev = head
        while ind >= 0:
            if ind == 0:
                if cur == prev:
                    head = cur.next
                else:
                    prev.next = cur.next
            prev = cur
            cur = cur.next
            ind -= 1
        return head
        
