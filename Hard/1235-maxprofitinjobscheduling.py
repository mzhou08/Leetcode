class Solution:
    def helper(self, orderedStarts, startTime, endTime, profit, idx):
        if (dp_res := self.dp[idx]) != -1:
            return dp_res

        job_idx = orderedStarts[idx]

        job_end = endTime[job_idx]
        job_profit = profit[job_idx]

        next_idx = idx
        next_start = startTime[
            orderedStarts[next_idx]
        ]

        while next_start < job_end:
            next_idx += 1

            if next_idx == len(startTime):
                break

            next_start = startTime[
                orderedStarts[next_idx]
            ]

        res = max(
            job_profit + self.helper(orderedStarts, startTime, endTime, profit, next_idx),
            self.helper(orderedStarts, startTime, endTime, profit, idx + 1)
        )

        self.dp[idx] = res

        return res

    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        """
        DP approach.
        Sort by start time.

        Max profit at index i is the max of:
            - profit if we do job i + max of end time of i
            - max profit if we don't do job i
        """

        n = len(startTime)

        orderedStarts = sorted(
            [i for i in range(n)],
            key=lambda x: startTime[x]
        )

        self.dp = [-1 for _ in range(n + 1)]
        self.dp[-1] = 0 # max profit of starting at index n (end of list) is 0

        return self.helper(
            orderedStarts,
            startTime,
            endTime,
            profit,
            0,
        )