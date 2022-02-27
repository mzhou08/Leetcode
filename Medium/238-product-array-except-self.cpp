#include <vector>
#include <iostream>

/* Runtime: 25 ms, faster than 75.53% of C++ online submissions for Product of Array Except Self.
   Memory Usage: 24.9 MB, less than 36.28% of C++ online submissions for Product of Array Except Self.
*/

/* Optimizations:
    Remove the prefix array
    Res becomes a modified version of suffixes
*/

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector <int> res;
        int pre = 1;
        
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            res.push_back(pre);
            pre = pre * nums[i];
        }        
        
        int suff = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            res[i] = suff * res[i];
            suff = suff * nums[i];
        }
        
        return res;
    }
};