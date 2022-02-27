#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector <int> prefixes;
        std::vector <int> suffixes;
        int pre = 1;
        int suff = 1;
        
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            prefixes.push_back(pre);
            pre = pre * nums[i];
            
            suffixes.push_back(suff);
            suff = suff * nums[n - i - 1];
        }
        
        std::vector <int> res;
        
        for (int i = 0; i < n; i++) {
            res.push_back(prefixes[i] * suffixes[n - i - 1]);
        }
        
        return res;
    }
};