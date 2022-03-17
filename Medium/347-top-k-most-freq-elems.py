# Runtime: 122 ms, faster than 69.34% of Python3 online submissions for Top K Frequent Elements.
# Memory Usage: 19.3 MB, less than 16.44% of Python3 online submissions for Top K Frequent Elements.

from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Initialize hash map with frequencies:
        # O (n)
        counts = Counter(nums)
        
        # Bucket Sort Approach - O (n)
        
        buckets = [[] for i in range((len(nums) + 1))]
        
        for num, count in counts.items():
            buckets[count].append(num)
            
        mostFreq = []
        
        for j in range(len(buckets) - 1, -1, -1):
            if buckets[j] != []:
                mostFreq.extend(buckets[j])
            
        return mostFreq[:k]
                
        
        
        # Heap Idea: O (n log k)
        
        # Turns the hash map nto a heap, O (k)
        # Then, we need to go through and get the
        # top k frequencies.
        # For the first k inserts, worst case O (k log k)
        # For the next n - k inserts, worst case O (log k).
        # So, we have total O (n log k) complexity
#         res = [mc[0] for mc in counts.most_common(k)]
        
#         return res