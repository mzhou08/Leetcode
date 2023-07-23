class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Need to sell before I buy. So I need to find the
        largest sum of non-overlapping transactions.

        DP Solution:
        At each index,
            - # previous transactions (bool)
            - held stock price (None if no stock held)
            - best profit
        """

        initial = float("-inf")
        sold_once = float("-inf")
        # here, bought_twice tracks balance.
        # that's why we don't need to know the price that we bought
        bought_twice = float("-inf")
        sold_twice = float("-inf")

        for price in prices:
            prev_initial = initial
            prev_sold_once = sold_once
            prev_bought_twice = bought_twice
            prev_sold_twice = sold_twice

            # initial tracks max balance (min starting price)
            initial = max(prev_initial, -price)

            # sold_once tracks max profit from selling once
            sold_once = max(prev_sold_once, price + prev_initial)

            # bought_twice tracks best balance when buying the
            # the second stock
            bought_twice = max(
                prev_bought_twice,
                prev_sold_once - price
            )

            # sold_twice tracks best profit when having sold twice
            sold_twice = max(
                prev_sold_twice,
                price + prev_bought_twice
            )

        print(sold_once, sold_twice)

        return max(0, sold_once, sold_twice)
