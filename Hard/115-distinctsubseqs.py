from pprint import pprint

class Solution:
    def numDistinctHelper(self, s, t, s_i, t_i):
        # print(f"{s_i} {t_i}")
        if self.dp[s_i][t_i] != -1:
            return self.dp[s_i][t_i]

        # skip the current letter in s
        res = self.numDistinctHelper(s, t, s_i + 1 , t_i)

        if s[s_i] == t[t_i]:
            res += self.numDistinctHelper(s, t, s_i + 1, t_i + 1)

        self.dp[s_i][t_i] = res

        return res


    def numDistinct(self, s: str, t: str) -> int:
        """
        DP Solution.

        At each index of s, have a correponding index of t.

        You can either include the string from s, or not.
        Recurrence is:
        f(is, it) = f(is + 1, it) + f(is + 1, it + 1)
        """

        # Note: We can optimize this by turning it iterative,
        # and using only the last seen row from top down.
        self.dp = [
            [-1 for _ in range(len(t) + 1)]
            for _ in range(len(s) + 1)
        ]


        for i in range(len(t)):
            self.dp[len(s)][i] = 0

        for i in range(len(s) + 1):
            self.dp[i][len(t)] = 1


        res = self.numDistinctHelper(s, t, 0, 0)

        # pprint(self.dp)

        return res
        