#include <vector>
#include <iostream>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        
        while (hi >= lo) {
            // std::cout << lo << " " << hi << "\n";
            
            int mid = ((hi - lo) / 2) + lo;
            
            if (nums[mid] == target) {
                // std::cout << mid;
                return mid;
            } else if (nums[mid] >= nums[lo]) {
                if (target < nums[mid] && target >= nums[lo]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                // nums[mid] < nums[lo];
                if (target > nums[mid] && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
            
        return -1;
        
    }
};