from collections import defaultdict

class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        val_counts = defaultdict(bool)
        res = set()

        for num in nums:
            if num + k in val_counts and (num, num + k) not in res:
                res.add((num, num + k))
            if num - k in val_counts and (num - k, num) not in res:
                res.add((num - k, num))

            val_counts[num] = True

        return len(res)

