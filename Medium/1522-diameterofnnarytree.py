"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:
    def helper(self, node):
        longest = 0
        longestRoot = 0

        longestChildren = [None, None]

        for v in node.children:
            longestV, longestVRoot = self.helper(v)

            if longestChildren[0] is None or longestVRoot >= longestChildren[0]:
                # new longest child path
                longestChildren[1] = longestChildren[0]
                longestChildren[0] = longestVRoot
            elif longestChildren[1] is None or longestVRoot > longestChildren[1]:
                longestChildren[1] = longestVRoot

            longest = max(longestV, longest)

        maxChildPlusRoot = (longestChildren[0] + 1 if longestChildren[0] is not None else 0)

        secMaxChildPlusRoot = (longestChildren[1] + 1 if longestChildren[1] is not None else 0)

        longestRoot = max(maxChildPlusRoot, secMaxChildPlusRoot)

        longest = max(longest, maxChildPlusRoot + secMaxChildPlusRoot)

        return (longest, longestRoot)

    def diameter(self, root: 'Node') -> int:
        """
        :type root: 'Node'
        :rtype: int
        """
        return self.helper(root)[0]