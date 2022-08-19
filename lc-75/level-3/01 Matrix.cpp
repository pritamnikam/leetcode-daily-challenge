/*
542.  01 Matrix
https://leetcode.com/problems/01-matrix/

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]


Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

namespace {
    class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int rows = mat.size(),
                cols = mat[0].size();

            vector<vector<int>> distance(
                rows,
                vector<int>(cols, INT_MAX)
            );

            queue<pair<int, int>> queue;

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (mat[i][j] == 0) {
                        queue.push({ i,j });
                        distance[i][j] = 0;
                    }
                }
            }

            vector<vector<int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            while (!queue.empty()) {
                pair<int, int> current = queue.front();
                queue.pop();

                for (auto dir : dirs) {
                    int x = current.first + dir[0],
                        y = current.second + dir[1];

                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        if (distance[x][y] > distance[current.first][current.second] + 1) {
                            distance[x][y] = distance[current.first][current.second] + 1;
                            queue.push({ x,y });
                        }
                    }
                }
            }

            return distance;
        }
    };
 }