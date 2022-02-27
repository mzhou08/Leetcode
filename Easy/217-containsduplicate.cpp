#include <unordered_set>

/* Runtime: 106 ms, faster than 73.58% of C++ online submissions for Contains Duplicate.
   Memory Usage: 51.4 MB, less than 48.21% of C++ online submissions for Contains Duplicate.
*/

//Using hash sets here to store seen vals

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set <int> vals;
        for (int i = 0; i < nums.size(); i++) {
            if (vals.find(nums[i]) != vals.end()) {
                return true;
            } else {
                vals.insert(nums[i]);
            }
        }
        return false;
    }
};