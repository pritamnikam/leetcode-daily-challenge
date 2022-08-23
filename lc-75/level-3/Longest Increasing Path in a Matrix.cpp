/*
329. Longest Increasing Path in a Matrix
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
*/

using namespace std;

#include <iostream>
#include <vector>


namespace {
    class Solution {
        vector<vector<int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        vector<vector<int>> cache;

    public:
        int longestIncreasingPath(vector<vector<int>>& matrix) {
            int answer = 0;
            cache = vector<vector<int>>(
                        matrix.size(),
                        vector<int>(matrix[0].size(), 0));

            for (int i = 0; i < matrix.size(); ++i) {
                for (int j = 0; j < matrix[i].size(); ++j) {
                    answer = max(answer, dfs(matrix, i, j));
                }
            }

            return answer;
        }

        int dfs(vector<vector<int>>& matrix, int i, int j) {

            if (cache[i][j]) {
                return cache[i][j];
            }

            int answer = 0;
            for (vector<int> d : dirs) {
                int x = i + d[0];
                int y = j + d[1];

                if (0 <= x && x < matrix.size() &&
                    0 <= y && y < matrix[i].size() &&
                    matrix[x][y] > matrix[i][j]) {

                    answer = max(answer, dfs(matrix, x, y));
                }
            }

            cache[i][j] = ++answer;
            return cache[i][j];
        }
    };
}

void testLongestIncreasingPath() {
    vector<vector<int>> matrix = { {9, 9, 4},{6, 6, 8},{2, 1, 1} };
    cout <<"Longest Increasing Path in a Matrix: " << Solution().longestIncreasingPath(matrix) << endl;
}