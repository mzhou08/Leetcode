from collections import defaultdict

class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        G = defaultdict(set)

        for r in roads:
            u = r[0]
            v = r[1]

            G[u].add(v)
            G[v].add(u)

        maxRank = 0

        for u in G:
            for v in G:
                if u != v:
                    rank = len(G[u]) + len(G[v])
                
                    if v in G[u]:
                        rank -= 1

                    maxRank = max(maxRank, rank)

        return maxRank