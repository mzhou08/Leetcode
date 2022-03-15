# Runtime: 1944 ms, faster than 52.16% of Python3 online submissions for Non-overlapping Intervals.
# Memory Usage: 52.9 MB, less than 42.15% of Python3 online submissions for Non-overlapping Intervals.

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals, key=lambda x: x[0])
        prevEnd = float("inf")
        count = 0
        for i in range(len(intervals)):
            # If there's an overlap
            if intervals[i][0] < prevEnd:
                # Compare the curr end and prevEnd
                if intervals[i][1] < prevEnd and prevEnd != float("inf"):
                    prevEnd = intervals[i][1]
                    count += 1
                elif intervals[i][1] >= prevEnd:
                    count += 1
                else:
                    prevEnd = intervals[i][1]
            else:
                # This killed me
                prevEnd = intervals[i][1]
                    
                
        return count
    
        # sort the intervals.
        # iterate through the intervals
        # if interval start < prev end, 
        #     then remove the one with the longer end,
        #     and set prevEnd to the longer end.
        #.    So we only need to add to count when the end of curr is grater than the end of prev