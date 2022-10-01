# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if (root is None):
            return []
        
        right_res = self.levelOrder(root.right)
        left_res = self.levelOrder(root.left)
        
        res = [[root.val]]
        
        while (right_res or left_res):
            if not right_res:
                res.extend(left_res)
                return res
            elif not left_res:
                res.extend(right_res)
                return res
            else:
                level = [left_res[0] + right_res[0]]
                
                del left_res[0]; del right_res[0]
                
                res.extend(level)
                
        return res