/*
1706. Where Will the Ball Fall
https://leetcode.com/problems/where-will-the-ball-fall/

You have a 2-D grid of size m x n representing a box, and you have n balls.
The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell
that can redirect a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.

Example 1:
Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
Output: [1,-1,-1,-1,-1]
Explanation: This example is shown in the photo.
Ball b0 is dropped at column 0 and falls out of the box at column 1.
Ball b1 is dropped at column 1 and will get stuck in the box between column 2 and 3 and row 1.
Ball b2 is dropped at column 2 and will get stuck on the box between column 2 and 3 and row 0.
Ball b3 is dropped at column 3 and will get stuck on the box between column 2 and 3 and row 0.
Ball b4 is dropped at column 4 and will get stuck on the box between column 2 and 3 and row 1.

Example 2:
Input: grid = [[-1]]
Output: [-1]
Explanation: The ball gets stuck against the left wall.

Example 3:
Input: grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
Output: [0,1,2,3,4,-1]


Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is 1 or -1.

*/

using namespace std;

#include <vector>

namespace {

    class Solution {
        int rows, cols;

        bool valid(int r, int c) {
            return r >= 0
                && c >= 0
                && r < rows
                && c < cols;
        }


        int DFS(vector<vector<int>>& grid, int r, int c) {
            if (r == rows)
                return c;

            if (valid(r, c)) {
                if (grid[r][c] == 1 and
                    valid(r, c + 1) and
                    grid[r][c + 1] == 1) {
                    return DFS(grid, r + 1, c + 1);
                }
                else if (grid[r][c] == -1 and
                    valid(r, c - 1) and
                    grid[r][c - 1] == -1) {
                    return DFS(grid, r + 1, c - 1);
                }
            }

            return -1;
        }

    public:
        // DFS
        vector<int> findBall(vector<vector<int>>& grid) {
            rows = grid.size(), cols = grid[0].size();

            vector<int> output(cols, -1);
            for (int c = 0; c < cols; ++c) {
                output[c] = DFS(grid, 0, c);
            }

            return output;
        }

        // Dynamic Programming
        vector<int> findBall2(vector<vector<int>>& grid) {
            int rows = grid.size(), 
                cols = grid[0].size();

            vector<int> result(cols, 0);

            for (int c = 0; c < cols; ++c) {
                int currentCol = c;
                for (int r = 0; r < rows; ++r) {
                    int nextColumn = currentCol + grid[r][currentCol];

                    if (nextColumn < 0 || nextColumn > cols - 1 ||
                        grid[r][currentCol] != grid[r][nextColumn]) {
                        result[c] = -1;
                        break;
                    }

                    result[c] = nextColumn;
                    currentCol = nextColumn;
                }
            }

            return result;
        }

    };

}  // namespace
