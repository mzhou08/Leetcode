class UFDS:
            def __init__(self, n):
                self.par = [i for i in range(n)]
                self.nodes = [1 for _ in range(n)]
                self.edges = [0 for _ in range(n)]

            def find(self, x):
                if self.par[x] != x:
                    self.par[x] = self.find(self.par[x])

                return self.par[x]

            def union(self, x, y):
                sx = self.nodes[x]
                sy = self.nodes[y]

                rx = self.find(x)
                ry = self.find(y)

                if sx < sy:
                    if rx != ry:
                        self.par[rx] = ry
                        self.nodes[ry] += sx
                        self.edges[ry] += self.edges[rx]
                    
                    self.edges[ry] += 1

                else:
                    if rx != ry:
                        self.par[ry] = rx
                        self.nodes[rx] += sy
                        self.edges[rx] += self.edges[ry]

                    self.edges[rx] += 1

class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1

        uf = UFDS(n)

        for u, v in connections:
            uf.union(u, v)

        roots = [i for i in range(n) if uf.find(i) == i]

        ccs = len(roots)

        extra_edges = sum(
            uf.edges[r] - (uf.nodes[r] - 1) for r in roots
        )

        if extra_edges >= ccs - 1:
            return ccs - 1
        
        return -1