#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int lo = 0;
        int hi = height.size() - 1;
        int maxWater = 0;
        
        while (lo != hi) {
            int smaller = std::min(height[lo], height[hi]);
            maxWater = std::max(
                smaller * (hi - lo),
                maxWater
            );
                
            if (height[lo] < height[hi]) {
                lo++;
            } else {
                hi--;
            }
        }
        
        return maxWater;
        
    }
};