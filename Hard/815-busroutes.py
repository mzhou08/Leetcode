from collections import deque

class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        """
        BFS Approach

        First, let's turn all routes into sets.

        Then run BFS
        """


        busroutes = [set(r) for r in routes]

        q = deque([i for i, r in enumerate(busroutes) if source in r])
        visited = set(q)

        d = 1

        if source == target:
            return 0

        while q:
            k = len(q)

            for _ in range(k):
                i = q.popleft()

                if target in busroutes[i]:
                    return d

                for j, r in enumerate(busroutes):
                    if busroutes[i].intersection(r) and j not in visited:
                        visited.add(j)
                        q.append(j)


            d += 1

        return -1