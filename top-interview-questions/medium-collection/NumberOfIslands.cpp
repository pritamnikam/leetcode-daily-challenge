/*
Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/

class Solution {
public:
    void maxAreaOfIsland(vector<vector<char>>& grid,
                        vector<vector<bool>>& visited,
                        int sr, int sc,
                        int& size) {
        if (sr < 0 || sr >= grid.size() || 
            sc < 0 || sc >= grid[0].size() ||
            grid[sr][sc] != '1' || visited[sr][sc]) {
            return;
        }

        ++size;
        visited[sr][sc] = true;

        maxAreaOfIsland(grid, visited, sr - 1, sc, size);
        maxAreaOfIsland(grid, visited, sr + 1, sc, size);
        maxAreaOfIsland(grid, visited, sr, sc - 1, size);
        maxAreaOfIsland(grid, visited, sr, sc + 1, size);
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int answer = 0;
        for (int sr = 0; sr < grid.size(); sr++) {
            for (int sc = 0; sc < grid[0].size(); sc++) {
                int runningTotal = 0;
                maxAreaOfIsland(grid, visited, sr, sc, runningTotal);
                if (runningTotal) {
                    ++answer;
                }
            }
        }

        return answer;
    }
};