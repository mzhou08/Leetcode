class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0; int top = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;

        vector<int> res;

        while (left <= right && top <= bottom) {
            // right -> left
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            
            top++;

            // top -> bottom
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }

            right--;

            if (left <= right && top <= bottom) {
                // left -> right
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }

                bottom--;

                // bottom -> top
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }

                left++;
            }
        }

        // cout <<"done";

        return res;
    }
};