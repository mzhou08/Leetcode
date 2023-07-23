class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        DFA Approach

        States are:
        Holding
        Sold
        Cooldown
        """

        holding_bal = float("-inf")
        sold_bal = float("-inf")
        cooldown_bal = 0

        for price in prices:
            prev_h, prev_s, prev_c = holding_bal, sold_bal, cooldown_bal

            holding_bal = max(holding_bal, prev_c - price)
            sold_bal = max(sold_bal, prev_h + price)
            cooldown_bal = max(cooldown_bal, prev_s)

        return max(0, sold_bal, cooldown_bal)