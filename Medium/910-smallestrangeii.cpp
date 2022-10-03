#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int smallestRangeII(vi& nums, int k) {
        sort(nums.begin(), nums.end());

        int mn = nums[0];
        int mx = nums.back();
        
        int res = mx - mn;

        for (int i = 0; i < nums.size() - 1; i++) {
            int curr = nums[i];
            int next = nums[i + 1];

            res = min(
                res,
                max(mx - k, curr + k) - min(mn + k, next - k)    
            );
        }

        // what if mn, max move in same direction?

        return res;


    }
};