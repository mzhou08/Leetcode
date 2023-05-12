class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo {1, 1};

        int curr = 2;
        
        while (curr <= n) {
            memo.push_back(memo[curr - 1] + memo[curr - 2]);
            curr++;
        }

        return memo.back();
    }
};