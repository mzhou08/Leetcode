class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        # turn cols into rows with zip

        return list(map(list, zip(*matrix)))