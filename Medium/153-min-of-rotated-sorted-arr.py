# Runtime: 49 ms, faster than 69.51% of Python3 online submissions for Find Minimum in Rotated Sorted Array.
# Memory Usage: 14.3 MB, less than 44.86% of Python3 online submissions for Find Minimum in Rotated Sorted Array.

class Solution:
    def findMin(self, nums: List[int]) -> int:
        lo = 0
        hi = len(nums) - 1
        
        while lo != hi:
            mid = (hi - lo) // 2 + lo
            if nums[mid] > nums[hi]:
                lo = mid + 1
            else:
                hi = mid
                
        return nums[lo]