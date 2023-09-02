class Solution:
    def helper(self, m, n):
        if self.memo[m][n] != -1:
            return self.memo[m][n]

        res = 0
        
        if (m, n) in self.priceMap:
            res = self.priceMap[(m, n)]

        # iterate over all horizantal cuts
        for i in range(m // 2):
            res = max(
                res,
                self.helper(m - i - 1, n)
                + self.helper(i + 1, n)
            )

        # iterate over all vertical cuts
        for i in range(n // 2):
            res = max(
                res,
                self.helper(m, n - i - 1)
                + self.helper(m, i + 1)
            )

        self.memo[m][n] = res
        return res


    def sellingWood(self, m: int, n: int, prices: List[List[int]]) -> int:
        """
        DP Solutions

        1. Convert prices into (h, w) -> price map
        2. DP on position of cut
        """

        self.priceMap = {}

        for h, w, p in prices:
            self.priceMap[(h, w)] = p

        self.memo = [
            [-1 for j in range(n + 1)] for i in range(m + 1)
        ]

        return self.helper(m, n)

        
