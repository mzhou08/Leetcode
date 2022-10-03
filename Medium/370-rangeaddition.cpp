#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vi getModifiedArray(int length, vvi& updates) {
        vi changes = vi(length + 1, 0);

        for (vi upd: updates) {
            int start = upd[0];
            int end = upd[1];
            int inc = upd[2];

            changes[start] += inc;
            changes[end + 1] -= inc;
        }

        int acc = 0;
        vi res;

        for (int i = 0; i < length; i++) {
            acc += changes[i];
            res.push_back(acc);
        }

        return res;
    }
};