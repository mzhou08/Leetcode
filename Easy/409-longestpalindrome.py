from collections import Counter

class Solution:
    def longestPalindrome(self, s: str) -> int:
        counts = Counter(s)

        odd_exists = False

        res = 0

        for count in counts.values():
            if count % 2 == 1:
                res += count - 1
                odd_exists = True
            else:
                res += count
            

        if odd_exists:
            res += 1
        
        return res