# Runtime: 235 ms, faster than 34.34% of Python3 online submissions for Longest Repeating Character Replacement.
# Memory Usage: 13.9 MB, less than 95.84% of Python3 online submissions for Longest Repeating Character Replacement.


# This was pretty difficult.
# The key idea is to not jump by the count of the most common char,
# but to just increment the right side of the window by 1 and reevaluate how much
# farther you can go.
# We also don't need a hi and lo pointer, since we can just keep moving the window
# if the condition is not satisfied (meaning the longest substring persists)

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        maxLen = 0
        mostComm = 0
        charCount = [0] * 26

        for i in range(len(s)):
            # Update the current char
            charCount[ord(s[i]) - ord("A")] += 1
            
            # What's the most common character?
            mostComm = max(charCount)
            
            if maxLen < k + mostComm:
                # Meaning we can still look at more characters
                maxLen += 1
            else:
                # Shift the window over by 1
                charCount[ord(s[i - maxLen]) - ord("A")] -= 1
            

        return maxLen
                
            
            
        
#         maxLen = 0
#         charCount = [0] * 26
#         for i in range(len(s)):
#             if i > k:
#                 charCount[ord(s[i - k])  - ord("A")] -= 1
#             charCount[ord(s[i]) - ord("A")] += 1
#             mostComm = max(count for count in charCount)
#             maxLen = max(maxLen, k + mostComm)
            
#         return maxLen