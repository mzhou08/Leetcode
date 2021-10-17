#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    struct dict {
        char val;
        int index;
        dict() : val(NULL), index(-2) {} 
        dict(char x, int ind) : val(x), index(ind) {}
    };

    vector<int> repeat(vector<dict*> d, char c) {
        vector<int> res;
        res.push_back(-1 /*index of dict*/);
        res.push_back(-1 /*index of repeat*/);
        for (int i = 0; i < d.size(); i++) {
            if (d[i]->val == c) {
                res[0] = i;
                res[1] = d[i]->index;
                return res;
            }
        }
        return res;
    }

    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        int longest = 0;
        vector<dict*> d;

        while (end < s.length()) {
            if (repeat(d, s[end])[0] != -1) {
                longest = max(longest, end - start);
                start = repeat(d, s[end])[1] + 1;

                //Update the dictionary entry for the char at s[end]
                dict* new_entry = new dict(s[end], end);
                d[repeat(d, s[end])[0]] = new_entry;
                //cout << repeat(d, s[end]) << '\n';
            } else if (end == s.length() - 1) {
                longest = max(longest, end - start + 1);
            } else {
                dict* new_entry = new dict(s[end], end);
                d.push_back(new_entry);
            }
            end++;
        }

        return longest;
    }
};

int main () {
    Solution S;
    cout << "\"abcabcbb\": exp. 3: " << S.lengthOfLongestSubstring("abcabcbb") << "\n";
    cout << "\"tmmzuxt\": exp. 5: " << S.lengthOfLongestSubstring("tmmzuxt") << "\n";
    cout << "\"\": exp. 0: " << S.lengthOfLongestSubstring("") << "\n";
}