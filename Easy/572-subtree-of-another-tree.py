# Runtime: 144 ms, faster than 71.10% of Python3 online submissions for Subtree of Another Tree.
# Memory Usage: 15.2 MB, less than 19.68% of Python3 online submissions for Subtree of Another Tree.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treeEq(self, t1, t2):
        if t1 == None and t2 == None:
            return True
        elif not t1 or not t2:
            return False
        else:
            return t1.val == t2.val and self.treeEq(t1.left, t2.left) and self.treeEq(t1.right, t2.right)
        
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if root == None:
            return False
        elif root.val == subRoot.val:
            return self.treeEq(root, subRoot) or self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
        else:
            return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)