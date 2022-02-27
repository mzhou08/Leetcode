#include <vector>
#include <algorithm>
#include <iostream>

/* Runtime: 177 ms, faster than 54.93% of C++ online submissions for Best Time to Buy and Sell Stock.
   Memory Usage: 93.3 MB, less than 54.04% of C++ online submissions for Best Time to Buy and Sell Stock.
*/

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // Sliding Window Approach
        int maxDiff = 0;
        int buy = 0;
        int sell = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] > prices[sell]) {
                sell = i;
                maxDiff = std::max(maxDiff, prices[sell] - prices[buy]);
            } else if (prices[i] < prices[buy]) {
                buy = i;
                sell = std::max(buy, sell);
                maxDiff = std::max(maxDiff, prices[sell] - prices[buy]);
            }
                
        }
        // cout << buy << sell << "\n";
        return maxDiff;
    }
};