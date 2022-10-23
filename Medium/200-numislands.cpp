#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vc> vvc;
typedef vector<vb> vvb;

class Solution {
public:
    void dfs(vvb &visited, vvc &grid, int row, int col) {
        char query_char = grid[row][col];
        
        if (visited[row][col]) return;

        visited[row][col] = true;

        if (row - 1 >= 0 && grid[row-1][col] == query_char) {
            dfs(visited, grid, row - 1, col);
        }

        if (row + 1 < grid.size() && grid[row+1][col] == query_char) {
            dfs(visited, grid, row + 1, col);
        }

        if (col - 1 >= 0 && grid[row][col - 1] == query_char) {
            dfs(visited, grid, row, col - 1);
        }

        if (col + 1 < grid[0].size() && grid[row][col + 1] == query_char) {
            dfs(visited, grid, row, col + 1);
        }
    }
    
    int numIslands(vvc & grid) {
        int res = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        vvb visited (
            rows,
            vb(cols, false)
        );

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (!visited[row][col]) {
                    char query_char = grid[row][col];

                    if (query_char == '1') res++;
                    dfs(visited, grid, row, col);
                }
            }
        }

        return res;
    }
};