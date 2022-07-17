/*
1706. Where Will the Ball Fall
https://leetcode.com/problems/where-will-the-ball-fall/

You have a 2-D grid of size m x n representing a box, and you have n balls. 
The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect
a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right 
corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left 
corner and is represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box
or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two 
boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of
at the bottom after dropping the ball from the ith column at the top, or -1 if the ball 
gets stuck in the box.


Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
Output: [1,-1,-1,-1,-1]


*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
        int rows;
        int cols;

        bool valid(int r, int c) {
            return r >= 0 && r < rows &&
                   c >= 0 && c < cols;
        }

        int DFS(vector<vector<int>>& grid, int r, int c) {
            if (r == rows)
                return c;

            if (valid(r, c)) {
                // '\' '\'
                // If current grid grid[r][c] is a \ then check it's right column -> grid[r][c+1] is same or not and Go to it's digonal place -> grid[r+1][c+1]
                if (grid[r][c] == 1) {
                    if (valid(r, c + 1) and grid[r][c + 1] == 1)
                        return DFS(grid, r + 1, c + 1);
                }
                else {
                    // '/' '/'
                    // if it is / then check it's left column grid[r][c-1] is same or not if it same then go -> grid[r+1][c-1]
                    if (valid(r, c - 1) and grid[r][c - 1] == -1)
                        return DFS(grid, r + 1, c - 1);
                }
            }

            return -1;
        }

    public:
        vector<int> findBall(vector<vector<int>>& grid) {
            rows = grid.size(), cols = grid[0].size();

            vector<int> ans(cols, 0);

            // DFS on every column
            for (int c = 0; c < cols; c++) {
                ans[c] = DFS(grid, 0, c);
            }

            return ans;
        }
    };
}

void testWhereWillTheBallFall() {
    /*
        Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
        Output: [1,-1,-1,-1,-1]
    */
    vector<vector<int>> grid = { {1,1,1,-1,-1} ,{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1} };
    vector<int> output = Solution().findBall(grid);

}
