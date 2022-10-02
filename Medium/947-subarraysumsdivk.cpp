#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vi count = vi(k, 0);

        int res = 0;
        count[0] = 1;
        int mod_prefix_sum = 0;

        for (int n: nums) {
            int rem = n % k;
            mod_prefix_sum = (mod_prefix_sum + rem + k) % k;

            res += count[mod_prefix_sum];
            
            count[mod_prefix_sum]++;
        }

        return res;
    }
};
//         vvi remainders;
//         vi dp;

//         for (int i = 0; i < nums.size(); i++) {
//             int prev_total;
//             int rem = nums[i] % k;

//             if (i != 0) {
//                 vi prev_rems = remainders[i - 1];
//                 prev_total = dp[i - 1];

//                 int new_total = prev_rems[rem] + dp[i - 1];
//                 if (rem == 0) new_total++;

//                 dp.push_back(new_total);

//                 vi rem_counts = vi(k, 0);

//                 for (int j = 0; j < k; j++) {
//                     int new_rem = (j + rem) % k;

//                     rem_counts[new_rem] = prev_rems[j];
//                 }
//                 rem_counts[rem]++;

//                 remainders.push_back(rem_counts);
//             } else {
//                 // i == 0
//                 int new_total = rem == 0 ? 1 : 0;
//                 dp.push_back(new_total);

//                 vi rem_counts = vi(k, 0);
//                 rem_counts[rem] = 1;

//                 remainders.push_back(rem_counts);
//             }
//         }

//         return dp.back();
//     }
// };