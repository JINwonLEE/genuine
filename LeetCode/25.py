# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def getNodes(head, k):
            cur = head
            nodes = []
            while cur != None and len(nodes) < k:
                nodes.append(cur)
                cur = cur.next
            return nodes 
       
        st = ListNode(next = head)
        prev = st
        nodes = getNodes(st.next, k)
        while len(nodes) == k:
            prev.next = nodes[-1]
            nodes[0].next = nodes[-1].next
            prev = nodes[0]
            for i in range(1, k):
                nodes[i].next = nodes[i-1]
            nodes = getNodes(nodes[0].next, k)
        return st.next

