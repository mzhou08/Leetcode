#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vvi sum_search(
        vi& candidates,
        int target,
        int upper,
        pair<vi, int> acc
    ) {
        vvi res;

        vi curr_terms = acc.first;
        int curr_sum = acc.second;

        for (int i = upper; i < candidates.size(); i++) {
            int new_sum = curr_sum + candidates[i];
            vi new_terms = curr_terms;
            new_terms.push_back(candidates[i]);

            if (new_sum < target) {
                vvi ith_res = sum_search(
                    candidates,
                    target,
                    i,
                    make_pair(new_terms, new_sum)
                );

                res.insert(end(res), begin(ith_res), end(ith_res));
            } else if (new_sum == target) {
                res.push_back(new_terms);
            }
        }

        return res;
    }

    vvi combinationSum(vi& candidates, int target) {
        vvi res = sum_search(candidates, target, 0, make_pair(vi(), 0));

        return res;
    }
};