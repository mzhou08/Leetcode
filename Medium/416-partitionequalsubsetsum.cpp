class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;

        for (auto num: nums) {
            total_sum += num;
        }

        if (total_sum % 2 != 0) return false;

        int target = total_sum / 2;

        // for index i, can we make a subset whose sum is i?
        vector<bool> dp (target + 1, false);

        dp[0] = true;

        for (auto &n: nums) {
        // for each number
            for (int j = target; j >= n; j--) {
                // update reachable sums
                dp[j] = dp[j] || dp[j - n];
            }
        }

        return dp[target];
    }
};