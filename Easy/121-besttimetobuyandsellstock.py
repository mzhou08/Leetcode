from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit: int = 0
        low: int = prices[0]

        for price in prices:
            if price < low:
                low = price
            if price - low > max_profit:
                max_profit = price - low
                
        return max_profit
            
            