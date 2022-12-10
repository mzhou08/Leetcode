class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)

        prefixSum = 0

        for i in range(len(nums)):
            if prefixSum == total - prefixSum - nums[i]:
                return i
            
            prefixSum += nums[i]


        return -1