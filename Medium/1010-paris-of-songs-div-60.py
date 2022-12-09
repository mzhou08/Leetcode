from collections import defaultdict

class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        modTimes = [t % 60 for t in time]

        prevModCounts = defaultdict(int)

        res = 0

        for t in modTimes:
            oppMod = (60 - t) % 60
            res += prevModCounts[oppMod]
            prevModCounts[t] += 1

        return res