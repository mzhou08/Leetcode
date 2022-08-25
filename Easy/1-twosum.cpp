#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> indices;

            for (int i = 0; i < nums.size(); i++) {
                // map<int, int>::iterator it = indices.find(target - nums[i]);

                // if (it != indices.end()) {
                if (indices.count(target - nums[i])) {
                    return {i, indices[target - nums[i]]};
                };

                indices[nums[i]] = i;
            };

            return {-1, -1};
        };
};