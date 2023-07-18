# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root):
        """
        Recursion approach

        For each node, store:
        max path ending at root
        max path overall
        """
        if root is None:
            return (float("-inf"), float("-inf"))
        # elif root.left is None and root.right is None:
        #     return (root.val, root.val)

        maxL, maxLRoot = self.helper(root.left)
        maxR, maxRRoot = self.helper(root.right)

        endatRoot = root.val + max(max(maxLRoot, maxRRoot), 0)

        maxatRoot = max(
            endatRoot,
            maxL,
            maxR,
            root.val + maxLRoot + maxRRoot,
            root.val
        )

        print(f"root: {root.val} maxatRoot: {maxatRoot} endatRoot: {endatRoot}")

        return (
            maxatRoot,
            endatRoot
        )
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        return self.helper(root)[0]