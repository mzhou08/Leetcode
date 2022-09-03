#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int res = nums[0];
        int curr_min = nums[0];
        int curr_max = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int temp_min = curr_min;
            
            curr_min = std::min(
                curr_min * nums[i],
                std::min(nums[i], curr_max * nums[i])
            );
            
            curr_max = std::max(
                curr_max * nums[i],
                std::max(nums[i], temp_min * nums[i])
            );
            
            res = std::max(res, curr_max);
        };
        return res;
    }
};