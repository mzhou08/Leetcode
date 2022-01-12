#include <string>
#include <vector>

/*
Submission Statistics:
Runtime: 242 ms, faster than 30.49% of C++ online submissions for Palindrome Partitioning.
Memory Usage: 53.5 MB, less than 61.86% of C++ online submissions for Palindrome Partitioning.
*/

class Solution {
public:
    std::vector< std::vector<std::string> > partition(std::string s) {
        int len = s.length();
        
        std::vector<std::vector<std::string> > res;
        std::vector<std::vector<bool> > palins (len, std::vector<bool> (len, false));
        std::vector<std::string> curr_list;

        dfs(s, 0, palins, res, curr_list);
        return res;
    }

    void dfs(std::string s,
        int start,
        std::vector<std::vector<bool> > &palins,
        std::vector<std::vector<std::string> > &res,
        std::vector<std::string> &curr_list) {
        if (start >= s.length()) {
            res.push_back(curr_list);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || palins[start + 1][end - 1])) {
                palins[start][end] = true;
                curr_list.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, palins, res, curr_list);
                curr_list.pop_back();
            }
        }
    }
};