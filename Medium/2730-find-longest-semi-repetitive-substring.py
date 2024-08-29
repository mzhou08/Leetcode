class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        n = len(s)
        
        adjacent_pair_idxs = [
            i for i in range(n - 1) if s[i] == s[i + 1]
        ]

        if len(adjacent_pair_idxs) <= 1:
            return n

        max_len = 0

        for i, left_idx_of_pair in enumerate(adjacent_pair_idxs):
            substring_len = None

            if i == 0:
                substring_len = adjacent_pair_idxs[i + 1] + 1
            elif i == len(adjacent_pair_idxs) - 1:
                substring_len = (n - 1) - adjacent_pair_idxs[i - 1]
            else:
                substring_len = adjacent_pair_idxs[i + 1] - adjacent_pair_idxs[i - 1]

            max_len = max(max_len, substring_len)

        return max_len
