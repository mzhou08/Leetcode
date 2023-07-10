# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseChunk(self, head, tail, k):
        """
        Reverse a length-k linked list chunk,
        return pointers to the head and tail of the reversed list
        """

        currNode = head
        
        nextNode = head.next
        for _ in range(1, k):
            temp = nextNode.next

            nextNode.next = currNode
            currNode = nextNode
            nextNode = temp

        return tail, head
        
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        ishead = True
        newHead = head

        prevNode = None
        chunkHead = head
        chunkTail = head

        while True:
            if chunkTail is None:
                return newHead

            for _ in range(k - 1):
                chunkTail = chunkTail.next
                if chunkTail is None:
                    return newHead

            nextNode = chunkTail.next

            newChunkHead, newChunkTail = self.reverseChunk(
                chunkHead, chunkTail, k
            )

            # set return value
            if ishead:
                newHead = newChunkHead
                ishead = False

            # link with rest of the list
            newChunkTail.next = nextNode
            if prevNode is not None:
                prevNode.next = newChunkHead
            
            # update pointers
            prevNode = newChunkTail

            chunkHead = nextNode
            chunkTail = nextNode

        return newHead