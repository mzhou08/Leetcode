from collections import defaultdict

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        """
        Store hash table mapping
        equations y = mx + b to sets of points that it goes through

        (m, b) -> {(x1, y1), ...}
        or (x) -> {...} for vertical lines

        the x entry default to 0, only used when we have vertical lines.
        """

        lines = defaultdict(set)

        if len(points) <= 2: return len(points)

        for p1 in points:
            for p2 in points:
                if p1 == p2: continue

                x1, y1 = p1[0], p1[1]
                x2, y2 = p2[0], p2[1]

                line_tuple = None

                if x2 == x1:
                    line_tuple = (x1)
                else:
                    # slope
                    m = (y2 - y1) / (x2 - x1)

                    # intercept
                    b = y1 - (m * x1)

                    line_tuple = (m, b)

                lines[line_tuple].add((x1, y1))
                lines[line_tuple].add((x2, y2))

        return max(
            len(pts) for pts in lines.values()
        )