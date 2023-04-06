/*
1254. Number of Closed Islands
https://leetcode.com/problems/number-of-closed-islands/

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Example 1:
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation:
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2


Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1

*/

using namespace std;

#include <iostream>

#include <vector>

namespace {
    class Solution {
        vector<vector<int>> directions = { {1,0}, {-1,0},{0,1},{0,-1} };
        int rows = 0, cols = 0, count = 0;
        bool isAlongBorder = false;

        void dfs(int r, int c, vector<vector<int>>& grid) {
            if (r < 0 || c < 0 || r >= rows || c >= cols) {
                return;
            }

            if (!grid[r][c]) {
                return;
            }

            if (r == 0 || c == 0 || r == rows - 1 || c == cols - 1) {
                isAlongBorder = true;
            }

            grid[r][c] = -1;
            for (auto& d : directions)
                dfs(r + d[0], c + d[1], grid);
        }

    public:
        int closedIsland(vector<vector<int>>& grid) {
            rows = grid.size();
            cols = grid[0].size();

            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {

                    isAlongBorder = false;
                    if (grid[r][c] == 0) {
                        dfs(r, c, grid);
                        if (!isAlongBorder)
                            ++count;
                    }
                }
            }

            return count;
        }
    };
}
