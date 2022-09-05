#include <vector>
#include <iostream>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        // hi >= lo instead of hi != lo for singleton cases 
        while (hi >= lo) {
            
            int mid = ((hi - lo) / 2) + lo;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= nums[lo]) {
                // this means that the left side is sorted, had to change to >=
                if (target < nums[mid] && target >= nums[lo]) {
                    hi = mid - 1;   // Since I did hi >= lo, we must never set hi or lo to mid
                } else {
                    lo = mid + 1;
                }
            } else {
                // nums[mid] < nums[lo]; so right side is sorted
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