class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /**
        Prefix Sum

        Compute prefix sums, now it's essentially Two Sum
        */

        int sum = 0;
        unordered_map<int, int> prefixCounts = {};
        prefixCounts[0] = 1;

        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (prefixCounts.find(k - sum) != prefixCounts.end()) {
                res += prefixCounts[k - sum];
            }

            prefixCounts[-sum]++;
        }

        return res;
    }
};