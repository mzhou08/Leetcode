class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        for i in range(len(matrix)):
            to_pop = matrix[i]
            for j in range(len(matrix)):
                matrix[j].append(matrix[i][0])
                matrix[i].pop(0)
        return [row.reverse() for row in matrix]
