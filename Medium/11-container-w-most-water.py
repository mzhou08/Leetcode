# Runtime: 961 ms, faster than 53.47% of Python3 online submissions for Container With Most Water.
# Memory Usage: 27.5 MB, less than 63.22% of Python3 online submissions for Container With Most Water.

class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        maxArea = 0
        
        while left <= right:
            maxArea = max(maxArea, min(height[left], height[right]) * (right - left))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
                
        return maxArea