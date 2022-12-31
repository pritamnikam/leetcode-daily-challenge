/*
980. Unique Paths III
https://leetcode.com/problems/unique-paths-iii/

You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Example 1:
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:
Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 20
1 <= m * n <= 20
-1 <= grid[i][j] <= 2
There is exactly one starting cell and one ending cell.

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
    public:
        int uniquePathsIII(vector<vector<int>>& grid) {
            int zero = 0, sx = 0, sy = 0;
            for (int r = 0; r < grid.size(); r++) {
                for (int c = 0; c < grid[0].size(); c++) {
                    // empty slots
                    if (grid[r][c] == 0) {
                        zero++;
                    }
                    else if (grid[r][c] == 1) { // start location
                        sx = r;
                        sy = c;
                    }
                }
            }
            return dfs(grid, sx, sy, zero);
        }
    private:
        vector<vector<int>>directions = { {0, 1}, {0, -1 }, {1, 0}, {-1, 0} };

        int dfs(vector<vector<int>>& grid, int x, int y, int zero) {
            if (x < 0
                || y < 0
                || x >= grid.size()
                || y >= grid[0].size()
                || grid[x][y] == -1) {
                return 0;
            }

            if (grid[x][y] == 2) {
                return zero == -1 ? 1 : 0;
            }

            grid[x][y] = -1; // mark visited
            zero--; // reduce the free slot

            int totalPaths = 0;
            for (auto& d : directions) {
                totalPaths += dfs(grid, x + d[0], y + d[1], zero);
            }

            grid[x][y] = 0; // mark unvisited
            zero++; // restore the avaialble slots

            return totalPaths;
        }
    };
}  // namespace

void testUniquePathsIII() {
    /*
        Example 1: Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]], Output: 2
    */

    vector<vector<int>> grid = { {1, 0, 0, 0},{0, 0, 0, 0},{0, 0, 2, -1} };
    cout << "Unique Paths III: " << Solution().uniquePathsIII(grid) << endl;
}
