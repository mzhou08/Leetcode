from collections import defaultdict

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Strictly Decreasing Neighbors
        """

        profit = 0

        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                profit += prices[i] - prices[i - 1]
        
        return profit
