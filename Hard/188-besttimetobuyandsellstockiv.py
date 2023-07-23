class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        """
        DFA Approach, like with BTTBASS III

        2k-length array where:
            dfa[2*i] = max balance after buying i + 1 times
            dfa[2*i + 1] = max balance after selling i + 1 times
        """

        dfa = [float("-inf") for _ in range(2 * k)]

        for price in prices:
            prev_sold = 0

            for i in range(k):
                prev_bought = dfa[2 * i]

                dfa[2 * i] = max(prev_bought, prev_sold - price)

                prev_sold = dfa[2 * i + 1]

                dfa[2 * i + 1] = max(
                    prev_sold, price + prev_bought
                )


        return max(0, *[dfa[2*i + 1] for i in range(k)])
        