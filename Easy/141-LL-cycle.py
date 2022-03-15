# Runtime: 60 ms, faster than 81.66% of Python3 online submissions for Linked List Cycle.
# Memory Usage: 17.7 MB, less than 37.27% of Python3 online submissions for Linked List Cycle.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        if not head:
            return False
        fast = head.next
        
        while fast != slow:
            if not fast or not fast.next:
                return False
            else:
                fast = fast.next.next
                slow = slow.next
        return True