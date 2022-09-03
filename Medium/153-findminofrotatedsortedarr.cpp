#include <vector>
#include <iostream>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        
        while (hi != lo) {
            int mid = ((hi - lo) / 2) + lo;
            // std::cout << "Before:" << lo << " " << hi <<"\n";
            
            if (nums[lo] <= nums[mid] && nums[mid] <= nums[hi]) {
                // std::cout << "case 1;" << "\n";
                hi = mid;
            } else if (nums[mid] < nums[hi] && nums[hi] < nums[lo]) {
                // std::cout << "case 2;" << "\n";
                hi = mid;
            } else {
                //nums[hi] < nums[lo] && nums[lo] < nums[mid])
                // std::cout << "case 3;" << "\n";
                lo = mid + 1;
            }
        }
        
        return nums[lo];
    }
};