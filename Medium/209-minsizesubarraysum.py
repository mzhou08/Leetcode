class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        """
        Prefix Sums and then 2 Pointers
        """

        start = 0
        end = 0

        n = len(nums)

        currSum = nums[0]

        shortest = 0

        while end != n:
            if currSum >= target:
                diff = end - start + 1
                shortest = min(shortest, diff) if shortest != 0 else diff
                
                if start < end:
                    currSum -= nums[start]
                    start += 1
                    continue

            end += 1
            if end != n:
                currSum += nums[end]

        return shortest