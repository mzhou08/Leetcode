from collections import defaultdict

class Solution:
    def helper(self, node):
        longest = 0
        longestRoot = 0

        self.visited.add(node)

        longestChildren = [None, None]

        for v in self.G[node]:
            if v not in self.visited:
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

    def treeDiameter(self, edges: List[List[int]]) -> int:
        G = defaultdict(list)   # adjacency list

        for edge in edges:
            u, v = edge
            G[u].append(v)
            G[v].append(u)

        self.G = G
        self.visited = set()
        
        return self.helper(0)[0]
