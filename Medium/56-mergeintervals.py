# Runtime: 199 ms, faster than 55.34% of Python3 online submissions for Merge Intervals.
# Memory Usage: 18.9 MB, less than 25.81% of Python3 online submissions for Merge Intervals.

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        if intervals != []:
            intervals = sorted(intervals, key=lambda x: x[0])

            start = intervals[0][0]
            end = intervals [0][1]
            for i in range(1, len(intervals)):
                if intervals [i][0] > end and intervals[i][0] > start:
                    res.append([start, end])
                    start = intervals[i][0]
                    end = intervals[i][1]
                else:
                    if intervals[i][0] <= end:
                        end = max(intervals[i][1], end)
                    if intervals[i][0] <= start:
                        start = min(intervals[i][0], start)
                
            res.append([start, end])
            return res
        else:
            return res