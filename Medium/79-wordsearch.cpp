typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;

class Solution {
public:
    bool dfs(vvb& visited, vvc& board, int i, int j, string word, int idx) {
        if (
            i < 0 || i >= board.size()
            || j < 0 || j >= board[0].size()
            || visited[i][j]
            || board[i][j] != word[idx]
        ) {
            // this is not a viable path
            return false;
        }

        if (idx == word.size() - 1) {
            return true;
        }

        visited[i][j] = true;

        bool res = (
            dfs(visited, board, i - 1, j, word, idx + 1)
            || dfs(visited, board, i + 1, j, word, idx + 1)
            || dfs(visited, board, i, j - 1, word, idx + 1)
            || dfs(visited, board, i, j + 1, word, idx + 1)
        );

        visited[i][j] = false;

        return res;
    }

    bool exist(vvc& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vvb visited = vector<vector<bool>>(
            m, vector<bool>(n, false)
        );

        bool res = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    // only start searching on squares with the same starting letter
                    res = res || dfs(visited, board, i, j, word, 0);
                }
            }
        }

        return res;
    }
};