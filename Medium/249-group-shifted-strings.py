# Runtime: 58 ms, faster than 39.44% of Python3 online submissions for Group Shifted Strings.
# Memory Usage: 14 MB, less than 61.02% of Python3 online submissions for Group Shifted Strings.

class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        shiftDict = {}
        for s in strings:
            diffs = [0]
            for i in range(1, len(s)):
                diffs.append((26 + ord(s[i])  - ord(s[i-1])) % 26)
            shiftDict[tuple(diffs)] = shiftDict.get(tuple(diffs), [])
            shiftDict[tuple(diffs)].append(s)
            
        return shiftDict.values()