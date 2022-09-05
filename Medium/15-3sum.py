class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        res = []
        for i in range(len(nums)):
            if nums[i] > 0:
                return res
            # Want to skip all duplicates
            elif i == 0 or nums[i] != nums[i - 1]:
            # TwoSum II Two Pointers approach
                hi = len(nums) - 1
                lo = i + 1
    
                while hi > lo:
                    if nums[hi] + nums[lo] == -nums[i]:
                        res.append([nums[i], nums[lo], nums[hi]])
                        lo += 1
                        hi -= 1
                        # Want the lo to skip all duplicates
                        while nums[lo] == nums[lo - 1] and lo < hi:
                            lo += 1
                    elif nums[hi] + nums[lo] < -nums[i]:
                        lo += 1
                    else:
                        hi -= 1

                
        return res
                
# No Sort Approach
# class Solution:
#     def threeSum(self, nums: List[int]) -> List[List[int]]:
#         res = set()
#         seen = set() # to remove duplicates, since list is unsorted
        
#         values_seen_in_iteration = {}
#         # Track what values we've seen in what iteration
#         # value: iteration pairs
        
#         for i, ival in enumerate(nums):
#             if ival not in seen: # so not duplicate
#                 seen.add(ival)
#                 for j, jval in enumerate(nums[i + 1:]): # iterate through rest of list
#                     complement = -jval - ival
#                     if complement in values_seen_in_iteration and values_seen_in_iteration[complement] == i:
#                         # if the complement is has been seen in the ith iteration
#                         res.add(tuple(sorted([ival, jval, complement])))
#                     # mark jval as having been seen in the ith iteration
#                     values_seen_in_iteration[jval] = i
                    
#         return res
        
# Unsorted Approach: gave me TLE        
#         pairsDict = {}
#         for i in range(len(nums)):
#             for j in range(i):
#                 # Append (i, j) to the list stored with key nums[i] + nums[j]
#                 pairsDict[nums[i] + nums[j]] = pairsDict.get(nums[i] + nums[j], [])
#                 pairsDict[nums[i] + nums[j]].append(tuple([i, j]))
        
#         res = []
        
#         # Go through nums again, check for matches
#         for k in range(len(nums)):
#             # If we have seen the negative already:
#             if -nums[k] in pairsDict:
#                 # Iterate through list of tuples,
#                 # check that k is not already in a tuple there
#                 for pair in pairsDict[-nums[k]]:
#                     if k != pair[0] and k != pair[1]:
#                         # We probably want to sort the values.
#                         if sorted([nums[k], nums[pair[0]], nums[pair[1]]]) not in res:
#                             res.append(sorted([nums[k], nums[pair[0]], nums[pair[1]]]))
                        
#         return res
                        
                    
            