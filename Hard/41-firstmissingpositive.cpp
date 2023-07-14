class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        /**
        We know that res <= n + 1.

        Iterate through nums.
        if nums[i] <= 0: nums[i] = -1
        to get rid of all negatives.

        Go through nums again.
        this time, keep a left pointer to the first
        idx that has not been modified.

        if nums[i] != -1:
            either has been modified or is still pristine
            if nums[i] <= n
                j

        Return left pointer + 1
        (0->1, .... n-1 -> n, n->n+1)
        */

        bool hasOne = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                hasOne = true;
            }
        }

        if (!hasOne) {
            return 1;
        }

        // clear out all infeasible numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        /**
        Key insight:
        in the previous idea, where we destructively overwrote
        index i if we saw i+1, the big issue is that we cannot
        differentiate between an untouched number vs. an index
        being stored there.

        Thus, the solution is to flip the sign instead. If the sign
        has been flipped, then it means it's been touched.
        */

        for (int i = 0; i < n; i++) {
            // we may need to indicate a new sighting
            int val = abs(nums[i]);
            if (nums[val - 1] > 0) {
                nums[val - 1] = -nums[val - 1];
            }
        }

        int res = n + 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res = i + 1;
                break;
            }
        }

        return res;
    }
};