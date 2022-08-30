#include <vector>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        
        std::vector<char> seen_parens;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                seen_parens.push_back(')');
            } else if (s[i] == '[') {
                seen_parens.push_back(']');
            } else if (s[i] == '{') {
                seen_parens.push_back('}');
            } else {
                if (seen_parens.size() == 0 || s[i] != seen_parens.back()) {
                    return false;
                };

                seen_parens.pop_back();
            };
        };

        return seen_parens.size() == 0;
    }
};