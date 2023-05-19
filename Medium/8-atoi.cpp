class Solution {
public:
    int myAtoi(string s) {
        int curr_idx = 0;

        // skip whitespaces
        while (curr_idx < s.size() && s[curr_idx] == ' ') {
            curr_idx++;
        }

        bool positive = true;
        // read in sign if it exists
        if (curr_idx < s.size() && s[curr_idx] == '-') {
            positive = false;
            curr_idx++;
        } else if (curr_idx < s.size() && s[curr_idx] == '+') {
            curr_idx++;
        }

        // read in digits
        vector<int> digits;
        bool seen_nonzero = false;

        while (curr_idx < s.size() && isdigit(s[curr_idx])) {
            if (s[curr_idx] == '0' && !seen_nonzero) {
                curr_idx++;
                continue;
            } else if (s[curr_idx] != 0) {
                seen_nonzero = true;
            }
            digits.push_back( ((int) s[curr_idx]) - ((int) '0') );
            curr_idx++;
        }

        // turn digits into integer.
        int pow10 = 1;
        int res = 0;

        int sign = positive ? 1 : -1;

        while (!digits.empty()) {
            long test_res = (long) res + (long) sign * pow10 * digits.back();
            if (sign < 0 && test_res < INT_MIN) {
                return INT_MIN;
            } else if (sign > 0 && test_res > INT_MAX) {
                return INT_MAX;
            }

            res += sign * pow10 * digits.back();
            digits.pop_back();

            cout << res << "\n";

            // check for overflow
            if (sign < 0 && res > 0) {
                return INT_MIN;
            } else if (sign > 0 && res < 0) {
                return INT_MAX;
            }

            if (pow10 <= INT_MAX / 10) {
                pow10 *= 10;
            } else {
                break;
            }
        }

        if (!digits.empty()) {
            if (sign < 0) {
                return INT_MIN;
            } else {
                return INT_MAX;
            }
        }
        return res;

    }
};