#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vvi permute(vi& nums) {
        if (nums.size() <= 1) {
            return vvi(1, nums);
        }

        vvi all_permutes;

        for (int i = 0; i < nums.size(); i++) {
            vi others = nums;
            others.erase(others.begin() + i);

            for (vi perm: permute(others)) {
                perm.insert(perm.begin(), nums[i]);
                all_permutes.push_back(perm);
            }
        }

        return all_permutes;
        
    }
};