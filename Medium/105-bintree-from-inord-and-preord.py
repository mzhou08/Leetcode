# Runtime: 218 ms, faster than 44.39% of Python3 online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
# Memory Usage: 53.5 MB, less than 51.77% of Python3 online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if inorder:
            # Pops the first thing from preorder.
            rootInd = inorder.index(preorder.pop(0))
            
            root = TreeNode(inorder[rootInd])
            root.left = self.buildTree(preorder, inorder[:rootInd])
            root.right = self.buildTree(preorder, inorder[rootInd + 1:])
            return root
        
        # root = TreeNode(val = preorder[0], left = None, right = None)
        # rootInd = inorder.index(root)
        # root.left = buildTree(preorder[1:], inorder[:rootInd])
        # root.right = buildTree(preorder[]
        
        # return root
        