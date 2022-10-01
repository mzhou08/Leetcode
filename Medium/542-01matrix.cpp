#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vvi updateMatrix(vvi& mat) {
        int num_rows = mat.size();
        if (num_rows == 0) {
            return mat;
        }
        
        int num_cols = mat[0].size();

        vvi dp = vvi(num_rows, vi(num_cols, num_rows + num_cols));

        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0) {
                        dp[i][j] = min(dp[i][j], 1 + dp[i-1][j]);
                    }
                    if (j > 0) {
                        dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
                    }
                }
            }
        }

        for (int i = num_rows - 1; i >= 0; i--) {
            for (int j = num_cols - 1; j >= 0; j--) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i < num_rows - 1) {
                        dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]);
                    }
                    if (j < num_cols - 1){
                        dp[i][j] = min(dp[i][j], 1 + dp[i][j + 1]);
                    }
                }
            }
        }

        return dp;
    }
};