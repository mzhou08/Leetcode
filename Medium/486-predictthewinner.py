class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)

        # DP on (lo, hi) tuples of indices.
        # dp[(i, j)] -> (p1_sum, p2_sum)

        dp = {}

        def helper(i, j):
            if (i, j) in dp:
                return dp[(i, j)]

            if j == i + 1:
                # singleton
                res = (nums[i], 0)
                dp[(i, j)] = res
                return res

            # if p1 chooses left
            first_if_left, sec_if_left = helper(i + 1, j)

            # if p1 chooses right
            first_if_right, sec_if_right = helper(i, j - 1)

            left_diff = nums[i] + sec_if_left - first_if_left
            right_diff = nums[j - 1] + sec_if_right - first_if_right

            if left_diff > right_diff:
                res = (nums[i] + sec_if_left, first_if_left)
            else:
                res = (nums[j - 1] + sec_if_right, first_if_right)

            dp[(i, j)] = res
            return res

        p1_res, p2_res = helper(0, n)

        return p1_res >= p2_res

            

