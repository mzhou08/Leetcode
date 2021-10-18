#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Submission Statistics:
Runtime: 132 ms, faster than 11.94% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 104.4 MB, less than 9.22% of C++ online submissions for Longest Substring Without Repeating Characters.
*/

class Solution {
public:
    struct dict {
        char val;
        int index;
        dict() : val(NULL), index(-2) {} 
        dict(char x, int ind) : val(x), index(ind) {}
    };

    vector<int> repeat(vector<dict*> d, char c, int start, int end) {
        vector<int> res;
        res.push_back(-1 /*index of dict*/);
        res.push_back(-1 /*index of repeat*/);
        for (int i = 0; i < d.size(); i++) {
            if (d[i]->val == c && d[i]->index >= start) {
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
            if (repeat(d, s[end], start, end)[0] != -1) {
                vector<int> rep = repeat(d, s[end], start, end);
                //cout << rep[0] << " " << rep[1] << '\n';
                
                longest = max(longest, end - start);
                start = rep[1] + 1;

                //Update the dictionary entry for the char at s[end]
                dict* new_entry = new dict(s[end], end);
                d[rep[0]] = new_entry;
                
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
    cout << "\"aabaab!bb\": exp. 3: " << S.lengthOfLongestSubstring("aabaab!bb") << "\n";
}