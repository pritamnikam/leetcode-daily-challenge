/*
417. Pacific Atlantic Water Flow
https://leetcode.com/problems/pacific-atlantic-water-flow/

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean.
The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches 
the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix
heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly 
north, south, east, and west if the neighboring cell's height is less than or equal to the 
current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain 
water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.


*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
    public:
        vector<vector<int>> res;
        vector<vector<int>> visited;

        vector<vector<int>> directions = { {1,0}, {-1,0}, {0,1}, {0,-1} };

        void dfs(vector<vector<int>>& matrix,
                int x, int y, 
                int pre, int preval) {

            if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()
                || matrix[x][y] < pre || (visited[x][y] & preval) == preval)
                return;

            visited[x][y] |= preval;

            if (visited[x][y] == 3)
                res.push_back({ x, y });

            for (auto d : directions) {
                dfs(matrix,
                    x + d[0],
                    y + d[1],
                    matrix[x][y],
                    visited[x][y]);
            }
        }

        vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
            if (matrix.empty()) return res;

            int m = matrix.size(),
                n = matrix[0].size();

            visited.resize(m, vector<int>(n, 0));

            for (int i = 0; i < m; i++) {
                dfs(matrix, i, 0, INT_MIN, 1);
                dfs(matrix, i, n - 1, INT_MIN, 2);
            }

            for (int i = 0; i < n; i++) {
                dfs(matrix, 0, i, INT_MIN, 1);
                dfs(matrix, m - 1, i, INT_MIN, 2);
            }

            return res;
        }
    };
}
