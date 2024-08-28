# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:

        if root is None:
            return []

        from collections import deque

        layers = deque([])

        q = deque([root])
        
        while len(q) > 0:
            curr_layer = []

            for _ in range(len(q)):
                node = q.popleft()

                curr_layer.append(node.val)

                if node.left is not None:
                    q.append(node.left)

                if node.right is not None:
                    q.append(node.right)

            layers.appendleft(curr_layer)

        return list(layers)
  
