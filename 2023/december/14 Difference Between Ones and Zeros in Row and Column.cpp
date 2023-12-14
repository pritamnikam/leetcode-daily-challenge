// 2482. Difference Between Ones and Zeros in Row and Column
// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> oneRows = vector<int>(m, 0), 
                    zeroRows = vector<int>(m, 0),
                    oneCols = vector<int>(n, 0),
                    zeroCols = vector<int>(n, 0);

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    oneRows[r]++;
                    oneCols[c]++;
                } else {
                    zeroRows[r]++;
                    zeroCols[c]++;
                }
            }
        }

        vector<vector<int>> diff = vector<vector<int>>(m, vector<int>(n, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                diff[r][c] = oneRows[r] + oneCols[c] - zeroRows[r] - zeroCols[c];
            }
        }

        return diff;
    }
};
