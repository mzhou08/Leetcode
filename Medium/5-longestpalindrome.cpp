class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        // when does the longestPalindrome string change?
        // when adding a new character completes a palindrome.
        // length of longest palindrome increases by 1 if at all.

        if (s.size() == 0) return "";

        vector<string> dp(s.size(), "");
        dp[0] = s.substr(0, 1);

        // Thus, as we scan across the string at index i,
        // check if s[i] == s[i - dp[i-1] - 1]. If so,
        // dp[i] = dp[i-1] + 2

        for (int i = 1; i < s.size(); i++) {
            // default to previous
            dp[i] = dp[i - 1];
    
            // if adding s[i] made a new longer palindrome
            string palinPlusOne = s.substr(
                i - dp[i - 1].size(), dp[i - 1].size() + 1
            );

            if (isPalindrome(palinPlusOne)) {
                dp[i] = palinPlusOne;
            }


            if (
                dp[i - 1].size() < i
                ) {
                // the last longest substring is not the whole previous string

                // test palindrome plus one on each end
                string palinPlusTwo = s.substr(
                    i - dp[i - 1].size() - 1, dp[i - 1].size() + 2
                );

                if (isPalindrome(palinPlusTwo)) {
                    dp[i] = palinPlusTwo;
                }
            }
            
        }

        return dp[s.size() - 1];
    }
};