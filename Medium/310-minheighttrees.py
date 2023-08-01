from collections import defaultdict

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        """
        KEY INSIGHT:

        Each tree only has one or two centroids,
        depending on the diameter.
        
        If odd, then one. If even, then two

        One way to do this is by continuously popping leaves.
        """

        G = defaultdict(set)

        if not edges:
            return [0]

        for u, v in edges:
            G[u].add(v)
            G[v].add(u)

        leaves = [v for v in G if len(G[v]) == 1]


        while len(G) > 2:
            nextLeaves = []

            while leaves:
                v = leaves.pop()

                u = G[v].pop()

                del G[v]

                G[u].remove(v)

                if len(G[u]) == 1:
                    nextLeaves.append(u)

            leaves = nextLeaves

        return list(G.keys())
