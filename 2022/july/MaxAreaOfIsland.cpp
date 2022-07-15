/*
695. Max Area of Island
https://leetcode.com/problems/max-area-of-island/

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally
(horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.


*/


using namespace std;

#include <vector>
#include <iostream>

namespace {
	class Solution {
		int rows, cols;

	public:
		int maxAreaOfIsland(vector<vector<int>>& grid) {
			rows = grid.size(),
			cols = grid[0].size();

			if (rows * cols == 0) return 0;

			int maxArea = 0;
			for (int i = 0; i < rows; ++i) {
				for (int j = 0; j < cols; ++j) {
					if (grid[i][j]) {
						int area = 0;
						getAreaOfIslang(grid, i, j, area);
						maxArea = max(maxArea, area);
					}
				}
			}

			return maxArea;
		}

		vector<vector<int>> directions = { {1,0},{-1,0},{0,1},{0,-1} };

		int getAreaOfIslang(vector<vector<int>>& grid, int r, int c, int& area) {
			if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) return;

			++area;
			grid[r][c] = 0;

			for (auto d : directions) {
				getAreaOfIslang(grid, r + d[0], c + d[1], area);
			}
		}
	};
}

void testArarOfIsland() {
  // Input: grid = [[0,0,0,0,0,0,0,0]]
  // Output: 0
  vector<vector<int>> grid = {{0,0,0,0,0,0,0,0}};
  cout << "Max Area of Island: " << Solution().maxAreaOfIsland(grid) << endl;
}


