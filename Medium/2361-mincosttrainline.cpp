#include <vector>

using namespace std;
typedef vector<long long> vll;

typedef vector<int> vi;
typedef vector<pair<long long, long long>> vpll;

class Solution {
public:
    vll minimumCosts(vi& regular, vi& express, int expressCost) {
        vpll dp (regular.size(), make_pair(0, 0));
        
        dp[0] = make_pair(regular[0], express[0] + expressCost);
        
        for (int i = 1; i < regular.size(); i++) {
            long long prev_regularCost = dp[i - 1].first;
            long long prev_expressCost = dp[i - 1].second;
            
            long long new_regularCost = min(
                prev_regularCost + regular[i],
                prev_expressCost + regular[i]
            );
            
            long long new_expressCost = min(
                prev_expressCost + express[i],
                prev_regularCost + express[i] + expressCost
            );
            
            dp[i] = make_pair(new_regularCost, new_expressCost);
        }
        
        vll res;
        
        for (pair<long long, long long> pr: dp) {
            res.push_back(min(pr.first, pr.second));
        }
        
        return res;
        
    }
};