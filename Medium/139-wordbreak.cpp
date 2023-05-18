class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool *dp = (bool *) calloc(sizeof(bool), s.size() + 1);
        dp[0] = true;

        // use a set to check membership
        set<string> words(wordDict.begin(), wordDict.end());

        for (int i = 0; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (words.find(s.substr(j, i-j)) != words.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }

        bool res = dp[s.size()];
        free(dp);
        return res;
    }
};