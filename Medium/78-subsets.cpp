class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // recursive approach
        // each element is either in the subset or is not.

        if (nums.empty()) {
            return {{}};
        }

        int last = nums.back();
        nums.pop_back();

        vector<vector<int>> rest = subsets(nums);

        vector<vector<int>> res;

        for (auto& subset : rest) {
            res.push_back(subset);
            subset.push_back(last);
            res.push_back(subset);
        }

        return res;
    }
};