# Runtime: 77 ms, faster than 10.28% of Python3 online submissions for Clone Graph.
# Memory Usage: 14.4 MB, less than 83.99% of Python3 online submissions for Clone Graph.

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

import collections

class Solution:
    def __init__(self):
        # initialize an empty dict of, which will store nodes & their copies.
        self.created = {}
    
    def cloneGraph(self, node: 'Node') -> 'Node':
        
        # Go through all nbors of node
        # create the appropriate new nodes,
        # then recursively call cloneGraph on those nodes
        # return node
        
        if node == None:
            return node
        
        if node in self.created.keys():
            return self.created[node]
        else:
            new = Node(val=node.val, neighbors=[])
            self.created[node] = new
            
        for nbor in node.neighbors:
            new.neighbors.append(self.cloneGraph(nbor))
                 
        return new
        
    # adj list = [[2, 4], [1, 3], [2, 4], [1, 3]]