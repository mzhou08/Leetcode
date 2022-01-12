#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int minCut(std::string s) {
        int len = s.length();
        
        std::vector<std::vector<std::string> > res;
        std::vector<std::vector<bool> > palins (len, std::vector<bool> (len, false));
        std::vector<std::string> curr_list;

        int min_cuts = len - 1;

        dfs(s, 0, palins, res, curr_list, min_cuts);
        return min_cuts;
    }

    void dfs(std::string s,
        int start,
        std::vector<std::vector<bool> > &palins,
        std::vector<std::vector<std::string> > &res,
        std::vector<std::string> &curr_list,
        int &min_cuts
        ) {

        if (start >= s.length()) {
            res.push_back(curr_list);
            min_cuts = std::min(min_cuts, (int) curr_list.size() - 1);

            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || palins[start + 1][end - 1])) {
                palins[start][end] = true;
                curr_list.push_back(s.substr(start, end - start + 1));
                
                dfs(s, end + 1, palins, res, curr_list, min_cuts);
                curr_list.pop_back();
            }
        }
    }
};

int main() {
    Solution sol;
    std::string s;
    std::cin >> s;
    int min_cuts = sol.minCut(s);
    std::cout << "min cuts: " << min_cuts;
}