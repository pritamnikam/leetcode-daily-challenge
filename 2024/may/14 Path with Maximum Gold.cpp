// 1219. Path with Maximum Gold
// https://leetcode.com/problems/path-with-maximum-gold/description/

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), maxGold = 0;

        // search for the path with the maximum gold starting from each cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maxGold = max(
                    maxGold,
                    dfs(
                        grid, rows, cols, i, j
                    )
                    );
            }
        }
        return maxGold;
    }

    private:
        const vector<int> DIRECTIONS = { 0, 1, 0, -1, 0 };

        int dfs(
            vector<vector<int>>& grid,
            int rows,
            int cols,
            int r,
            int c
        ) {
            // base case:
            if (r < 0 || c < 0 || r == rows || c == cols || grid[r][c] == 0) {
                return 0;
            }

            int maxGold = 0;

            int originalVal = grid[r][c];
            grid[r][c] = 0;

            for (int d = 0; d < 4; d++) {
                maxGold = max(
                    maxGold,
                    dfs(
                        grid,
                        rows,
                        cols,
                        r + DIRECTIONS[d],
                        c + DIRECTIONS[d + 1]
                    )
                );

            }

            grid[r][c] = originalVal;
            return maxGold + originalVal;
        }
};
