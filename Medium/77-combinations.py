class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:

        res = []

        def helper(acc, i):
            if len(acc) == k:
                res.append(list(acc))
                return

            for num in range(i + 1, n + 1):
                acc.append(num)
                helper(acc, num)
                acc.pop()

            return

        
        helper([], 0)

        return res