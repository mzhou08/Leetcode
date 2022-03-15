# Runtime: 56 ms, faster than 21.77% of Python3 online submissions for Invert Binary Tree.
# Memory Usage: 13.8 MB, less than 70.23% of Python3 online submissions for Invert Binary Tree.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root == None: return None
        temp = root.left
        root.left = self.invertTree(root.right)
        root.right = self.invertTree(temp)
        
        return root