from collections import Counter

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        freqs = Counter(nums)

        freqs = sorted(freqs.items(), key=lambda x: x[0])

        """
        DP Approach:
        We go through and for each idx, select whether or not we
        use it.

        Probably go top-down for better memory usage.
        """

        one_above = (len(freqs) + 1, 0)
        two_above = (len(freqs) + 1, 0)

        for i in range(len(freqs) - 1, -1, -1):
            profit = freqs[i][0] * freqs[i][1]

            if one_above[0] - freqs[i][0] > 1:
                i_picked = (
                    freqs[i][0],
                    profit + max(
                        one_above[1], two_above[1]
                    )
                )

            else:
                i_picked = (
                    freqs[i][0],
                    profit + two_above[1]
                )

            if one_above[1] > two_above[1]:
                two_above = one_above

            one_above = i_picked

        return max(one_above[1], two_above[1])                
