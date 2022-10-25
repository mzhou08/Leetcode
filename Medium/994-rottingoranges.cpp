#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> pii;
typedef pair<pii, int> pp;

typedef set< pair<int, int> >  spi;
typedef queue<pp> qpp;


class Solution {
public:
    int orangesRotting(vvi& grid) {
        spi fresh_oranges = spi();

        qpp rotten_oranges = qpp();

        int rows = grid.size(); int cols = grid[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) {
                    fresh_oranges.insert(
                        make_pair(row, col)
                    );
                } else if (grid[row][col] == 2) {
                    rotten_oranges.push(
                        make_pair(
                            make_pair(row, col),
                            0
                        )
                    );
                }
            }
        }

        int time_elapsed = 0;

        while (!fresh_oranges.empty()) {
            if (rotten_oranges.empty()) return -1;
            pp rotten_timepair = rotten_oranges.front();
            pii rotten_coords = rotten_timepair.first;
            time_elapsed = rotten_timepair.second;
            time_elapsed++;
 
            rotten_oranges.pop();

            int row = rotten_coords.first;
            int col = rotten_coords.second;

            if (row - 1 >= 0) {
                pair<int, int> up = make_pair(row-1, col);
                if (fresh_oranges.find(up) != fresh_oranges.end()) {
                    // row-1, col is now rotten
                    fresh_oranges.erase(up);
                    rotten_oranges.push(
                        make_pair(up, time_elapsed)
                    );
                }
            }

            if (row + 1 < rows) {
                pair<int, int> down = make_pair(row+1, col);
                if (fresh_oranges.find(down) != fresh_oranges.end()) {
                    // row+1, col is now rotten
                    fresh_oranges.erase(down);
                    rotten_oranges.push(
                        make_pair(down, time_elapsed)
                    );
                }
            }

            if (col - 1 >= 0) {
                pair<int, int> left = make_pair(row, col-1);
                if (fresh_oranges.find(left) != fresh_oranges.end()) {
                    // row, col-1 is now rotten
                    fresh_oranges.erase(left);
                    rotten_oranges.push(
                        make_pair(left, time_elapsed)
                    );
                }
            }

            if (col + 1 < cols) {
                pair<int, int> right = make_pair(row, col+1);
                if (fresh_oranges.find(right) != fresh_oranges.end()) {
                    // row, col+1 is now rotten
                    fresh_oranges.erase(right);
                    rotten_oranges.push(
                        make_pair(right, time_elapsed)
                    );
                }
            }
        }

        return time_elapsed;
    }
};