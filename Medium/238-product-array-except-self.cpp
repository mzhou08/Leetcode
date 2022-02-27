#include <vector>
#include <iostream>

/* Runtime: 46 ms, faster than 26.17% of C++ online submissions for Product of Array Except Self.
   Memory Usage: 26.3 MB, less than 6.60% of C++ online submissions for Product of Array Except Self.
*/

/* Optimizations:
    Remove the prefix array
    ???
*/

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector <int> suffixes;
        int suff = 1;
        
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            suffixes.push_back(suff);
            suff = suff * nums[n - i - 1];
        }
        
        std::vector <int> res;
        int pre = 1;
        
        for (int i = 0; i < n; i++) {
            res.push_back(pre * suffixes[n - i - 1]);
            pre = pre * nums[i];
        }
        
        return res;
    }
};