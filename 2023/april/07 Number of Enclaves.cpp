/*
1020. Number of Enclaves
https://leetcode.com/problems/number-of-enclaves/

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Example 2:
Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
	class Solution {
		const vector<vector<int>> directions = { {1,0}, {-1, 0}, {0, 1}, {0, -1} };

		void numEnclaves(
			vector<vector<int>>& grid,
			vector<vector<bool>>& visited,
			int i, int j,
			int& area,
			bool& connected)
		{
			if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0) {
				connected = true;
				return;
			}

			if (visited[i][j] || grid[i][j] == 0)
				return;

			visited[i][j] = true;
			++area;

			for (auto d : directions)
				numEnclaves(grid, visited, i + d[0], j + d[1], area, connected);
		}

	public:
		int numEnclaves(vector<vector<int>>& grid) {
			vector<vector<bool>>visited(grid.size(),
				vector<bool>(grid[0].size(), false));
			int answer = 0;
			for (int i = 0; i < grid.size(); ++i) {
				for (int j = 0; j < grid[0].size(); ++j) {
					if (grid[i][j] && !visited[i][j]) {
						bool connected = false;
						int area = 0;
						numEnclaves(grid, visited, i, j, area, connected);
						if (connected == false)
							answer += area;
					}
				}
			}

			return answer;
		}
	};
}
