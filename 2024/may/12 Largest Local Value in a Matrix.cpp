// 2373. Largest Local Value in a Matrix
// https://leetcode.com/problems/largest-local-values-in-a-matrix


class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> output(n - 2, vector<int>(n - 2, 0));
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                output[i][j] = findMax(grid, i, j);
            }
        }

        return output;
    }

private:
    int findMax(vector<vector<int>>& grid, int x, int y) {
        int maxElement = 0;
        for (int i = x; i <= x + 2; i++) {
            for (int j = y; j <= y + 2; j++) {
                maxElement = max(maxElement, grid[i][j]);
            }
        }
        return maxElement;
    }
};
