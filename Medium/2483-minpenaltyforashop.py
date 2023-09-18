class Solution:
    def bestClosingTime(self, customers: str) -> int:
        pen = 0
        best_penalty = 0
        best_time = 0

        for i, c in enumerate(customers):
            if c == "Y":
                pen -= 1
            else:
                pen += 1

            if pen < best_penalty:
                best_penalty = pen
                best_time = i + 1

        
        return best_time
