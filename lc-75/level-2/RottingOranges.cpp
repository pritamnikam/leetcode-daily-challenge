/*
994. Rotting Oranges
https://leetcode.com/problems/rotting-oranges/

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
If this is impossible, return -1.


*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

namespace {
	class Solution {
		const int kEmpty = 0;
		const int kFresh = 1;
		const int kRotten = 2;
		int answer = 0;

		int rows;
		int cols;

	public:
		int orangesRotting(vector<vector<int>>& grid) {
			queue<pair<int, int>> q;

			rows = grid.size();
			cols = grid[0].size();
			vector<vector<bool>> visited(grid.size(), 
										 vector<bool>(grid[0].size(), false));

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					if (grid[i][j] == kRotten) {
						q.push(make_pair(i, j));
					}
				}
			}

			answer = orangesRotting(grid, visited, q);

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					if (grid[i][j] == kFresh) {
						return -1;
					}
				}
			}

			return answer;
		}


	private:
		vector<vector<int>> directions = { {1,0}, {-1,0}, {0,1}, {0,-1} };

		int orangesRotting(vector<vector<int>>& grid, 
						   vector<vector<bool>>& visited, 
						   queue<pair<int, int>>& q) {
			answer = 0;
			while (!q.empty()) {
				int size = q.size();

				for (int i = 0; i < size; ++i) {
					pair<int, int> cur = q.front();
					q.pop();

					int r = cur.first,
						c = cur.second;

					visited[r][c] = true;
					for (auto d : directions) {
						int x = r + d[0], 
							y = c + d[1];

						if (x >= 0 && y >= 0 &&
							x < rows && y < cols &&
							!visited[x][y] &&
							grid[x][y] == kFresh) {
							q.push({ x, y });
							grid[x][y] = kRotten;
						}
					}

					if (!q.empty())
						++answer;
				}
			}

			return answer;
		}
	};
} // namespace
