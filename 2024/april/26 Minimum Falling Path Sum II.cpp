// 1289. Minimum Falling Path Sum II
// https://leetcode.com/problems/minimum-falling-path-sum-ii

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for (int row = rows - 2; row >= 0; --row) {
            for (int col = 0; col < cols; ++col) {
                int currentMin = INT_MAX;
                for(int i=0;i<cols;i++){
                    if (i != col) {
                        currentMin = min(currentMin, grid[row+1][i]);
                    }
                }

                grid[row][col] += currentMin;
            }
        }

        int answer = INT_MAX;
        for (int col = 0; col < cols; ++col) {
            answer = min(answer, grid[0][col]);
        }

        return answer;
    }
};
