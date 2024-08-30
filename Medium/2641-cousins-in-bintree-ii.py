# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        store level-by-level, then go in and change the individual pointers
        """

        if root is None:
            return root

        # node, sibling val
        curr_level = [(root, 0)]

        while len(curr_level) > 0:
            level_sum = sum([node.val for node, _ in curr_level])

            next_level = []

            for node, sibling_val in curr_level:
                node.val = level_sum - node.val - sibling_val

                if node.left is not None:
                    right_val = node.right.val if node.right is not None else 0

                    next_level.append((node.left, right_val))

                if node.right is not None:
                    left_val = node.left.val if node.left is not None else 0

                    next_level.append((node.right, left_val))

            curr_level = next_level

        return root
