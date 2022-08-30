#include <vector>

class Solution {
    public:
        int maxSubArray(std::vector<int>& nums) {
            // Approach 1: resetting sum every time it gets below 0 
            int curr_sum = nums[0];
            int max_sum = curr_sum;

            for (int i = 1; i < nums.size(); i++) {
                curr_sum = std::max(curr_sum + nums[i], nums[i]);
                max_sum = std::max(max_sum, curr_sum);
            }

            return max_sum;
        };

        int maxSubArray2(std::vector<int>& nums) {
            // Approach 2: Divide and Conquer recursion
            // Find best sum of the elems on the left and right, radiating from middle
            // Then recursively call function on left and right halves to find max sum
            // take the max of the three and return
        }
};