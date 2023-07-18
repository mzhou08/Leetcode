class Solution:
    def goodBinaryStrings(self, minLength: int, maxLength: int, oneGroup: int, zeroGroup: int) -> int:

        MOD_BASE = 10 ** 9 + 7

        dp = [0 for _ in range(maxLength + 1)]
        dp[0] = 1

        g = gcd(oneGroup, zeroGroup)

        for i in range(1, maxLength + 1):
            if i % g: continue

            count = (
                (dp[i - oneGroup] if i >= oneGroup else 0) +
                (dp[i - zeroGroup] if i >= zeroGroup else 0)
            )

            dp[i] += count % MOD_BASE
            dp[i] %= MOD_BASE
        
        return sum(dp[minLength: maxLength + 1]) % MOD_BASE