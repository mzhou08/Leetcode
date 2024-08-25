class Solution:
    def sum_after_taking_from_bucket(self, *, total_sum, bucket, num_items_to_take):
        if len(bucket) < num_items_to_take:
            return float("-inf")
        else:
            return total_sum - sum(bucket[-num_items_to_take:])

    def maxSumDivThree(self, nums: List[int]) -> int:
        total_sum = 0
        remainder_1_bucket = []
        remainder_2_bucket = []

        for n in nums:
            total_sum += n

            n_remainder = n % 3

            if n_remainder == 1:
                remainder_1_bucket.append(n)    
            elif n_remainder == 2:
                remainder_2_bucket.append(n)

        remainder_1_bucket = sorted(remainder_1_bucket, reverse=True)
        remainder_2_bucket = sorted(remainder_2_bucket, reverse=True)

        total_sum_remainder = total_sum % 3 

        if total_sum_remainder == 0:
            return total_sum

        elif total_sum_remainder == 1:
            return max(
                0,
                self.sum_after_taking_from_bucket(
                    total_sum=total_sum,
                    bucket=remainder_1_bucket,
                    num_items_to_take=1
                ),
                self.sum_after_taking_from_bucket(
                    total_sum=total_sum,
                    bucket=remainder_2_bucket,
                    num_items_to_take=2
                )
            )

        elif total_sum_remainder == 2:
            return max(
                0,
                self.sum_after_taking_from_bucket(
                    total_sum=total_sum,
                    bucket=remainder_1_bucket,
                    num_items_to_take=2
                ),
                self.sum_after_taking_from_bucket(
                    total_sum=total_sum,
                    bucket=remainder_2_bucket,
                    num_items_to_take=1
                )
            )
