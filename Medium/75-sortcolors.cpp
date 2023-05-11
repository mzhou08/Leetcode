class Solution {
public:
    void sortColors(vector<int>& nums) {
        // one past the rightmost 0
        int zero_one_boundary = 0;

        // one before the leftmost 2
        int one_two_boundary = nums.size() - 1;
        
        int curr = 0;
        
        while (curr <= one_two_boundary) {
    
            if (nums[curr] == 0) {
                // swap with zero_one_boundary
                nums[curr] = nums[zero_one_boundary];
                nums[zero_one_boundary] = 0;
        
                // increment both; if nums[curr] != 0
                // it will get swapped later if needed
                zero_one_boundary++;
                curr++;
            } else if (nums[curr] == 2) {
                // swap with one_two_boundary
                nums[curr] = nums[one_two_boundary];
                nums[one_two_boundary] = 2;

                // only decrement the boundary, still need to case on curr
                one_two_boundary--;
            } else {
                // we've seen a 1, so keep going
                curr++;
            }
        }
    }
};