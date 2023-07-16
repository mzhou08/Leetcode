from collections import defaultdict
from collections import deque

class Solution:
    def flip_edge(self, u, v):
        # flip the edge u->v into v->u
        self.in_edges[v].remove(u)
        self.out_edges[u].remove(v)

        self.in_edges[u].add(v)
        self.out_edges[v].add(u)

    def dfs(self):
        res = 0

        frontier = deque([0])
        visited = set()

        while frontier:
            node = frontier.pop()

            if node == 0:
                # all out-edges must be flipped to in_edges
                for v in set(self.out_edges[0]):
                    self.flip_edge(0, v)
                    res += 1
            else:
                # swap all non-visited out edges
                for v in set(self.out_edges[node]):
                    if v not in visited:
                        self.flip_edge(node, v)
                        res += 1

            visited.add(node)

            for v in self.in_edges[node]:
                frontier.append(v)
        
        return res
            
            

    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        """
        The graph is a tree, so no cycles.

        For each neighbor of 0, all other edges must be inbound.

        Similar for the rest.
        """

        self.in_edges = defaultdict(set)
        self.out_edges = defaultdict(set)

        for conn in connections:
            u = conn[0]
            v = conn[1]

            self.in_edges[v].add(u)
            self.out_edges[u].add(v)

        return self.dfs()