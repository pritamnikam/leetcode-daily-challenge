// 463. Island Perimeter
// https://leetcode.com/problems/island-perimeter

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int answer = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    answer += 4;

                    if (i > 0 && grid[i-1][j] == 1) answer -= 2;
                    if (j > 0 && grid[i][j-1] == 1) answer -= 2;
                }
            }
        }

        return answer;
    }
};
