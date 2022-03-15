# Runtime: 155 ms, faster than 44.93% of Python3 online submissions for Group Anagrams.
# Memory Usage: 17.9 MB, less than 55.07% of Python3 online submissions for Group Anagrams.

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagramDict = {}
        for s in strs:
            skey = "".join(sorted(s))
            anagramDict[skey] = anagramDict.get(skey, [])
            anagramDict[skey].append(s)
            
        return anagramDict.values()