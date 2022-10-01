#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int ccHelp(vector<int>& dp, vector<int> coins, int amount) {
        if (amount == 0) return 0;
        
        int min_coins = INT_MAX;
        
        if (dp[amount] != -2) {
            return dp[amount];
        }
        
        for (int c: coins) {
            if (c <= amount) {
                int c_coins = ccHelp(dp, coins, amount - c);
                if (c_coins != -1) {
                    min_coins = min(min_coins, 1 + c_coins);
                }
            }
        }
        
        if (min_coins == INT_MAX) {
            dp[amount] = -1;
            return -1;
        }
        
        dp[amount] = min_coins;
        return min_coins;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -2);
        
        dp[0] = 0;
        
        return ccHelp(dp, coins, amount);
    }
};