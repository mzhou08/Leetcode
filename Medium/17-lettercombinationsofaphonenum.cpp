class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char, vector<string>> num_to_chars = {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}
        };

        if (digits.size() == 0) {
            return {};
        } else if (digits.size() == 1) {
            return num_to_chars[digits[0]];
        }

        char first = digits[0];

        vector<string> res = letterCombinations(digits.substr(1, digits.size() - 1));

        int n = res.size();

        for (int i = 0; i < n; i++) {
            for (auto &c : num_to_chars[first]) {
                res.push_back(
                    c + res[0]
                );
            }

            res.erase(res.begin());
        }

        return res;
    }
};