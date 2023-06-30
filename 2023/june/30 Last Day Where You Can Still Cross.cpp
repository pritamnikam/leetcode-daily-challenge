/*
1970. Last Day Where You Can Still Cross
https://leetcode.com/problems/last-day-where-you-can-still-cross/

There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.



Example 1:


Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.
Example 2:


Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.
Example 3:


Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.


Constraints:

2 <= row, col <= 2 * 104
4 <= row * col <= 2 * 104
cells.length == row * col
1 <= ri <= row
1 <= ci <= col
All the values of cells are unique.

*/
using namespace std;

#include <iostream>
#include <vector>

namespace {
    class DisjointSet {
    private:
        vector<int> size, par;

    public:
        DisjointSet(int n) {
            size.resize(n, 1);
            par.resize(n);
            for (int i = 0; i < n; i++)
                par[i] = i;
        }

        int findPar(int x) {
            if (par[x] == x) return x;
            return par[x] = findPar(par[x]);
        }

        void merge(int x, int y) {
            int px = findPar(x);
            int py = findPar(y);

            if (px == py) return;

            if (size[px] < size[py]) {
                par[px] = py;
                size[py] += size[px];
            }
            else {
                par[py] = px;
                size[px] += size[py];
            }
        }

        bool connected(int x, int y) {
            return findPar(x) == findPar(y);
        }
    };

    class Solution {
    public:
        int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
            vector<vector<int>> grid(row, vector<int>(col, 0));

            // Mark the cells as flooded (1) based on the input cells array
            for (auto& x : cells) {
                grid[x[0] - 1][x[1] - 1] = 1;
            }

            int dirs[5] = { -1, 0, 1, 0, -1 }; // Directions array for easy traversal (up, right, down, left)
            int totalCells = row * col; // Total number of cells in the grid
            int rowStart = totalCells, rowEnd = totalCells + 1; // Virtual cells representing the top and bottom rows
            DisjointSet ds(totalCells + 2); // Create a disjoint-set data structure with totalCells + 2 elements (including virtual cells)

            // Iterate over the grid and establish initial connections between adjacent land cells
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dirs[k];
                        int nj = j + dirs[k + 1];

                        if (ni >= 0 && ni < row && nj >= 0 && nj < col && grid[ni][nj] == 0) {
                            int nodeVal = i * col + j;
                            int nextVal = ni * col + nj;
                            // Merge the current node and the next node (if they are both land cells)
                            ds.merge(nodeVal, nextVal);
                        }
                    }
                }
            }

            // Iterate over the flooded cells in reverse order
            for (int c = totalCells - 1; c >= 0; c--) {
                int i = cells[c][0] - 1;
                int j = cells[c][1] - 1;
                int nodeVal = i * col + j;
                grid[i][j] = 0; // Mark the cell as land (unflooded)

                for (int k = 0; k < 4; k++) {
                    int ni = i + dirs[k];
                    int nj = j + dirs[k + 1];

                    if (ni >= 0 && ni < row && nj >= 0 && nj < col && grid[ni][nj] == 0) {
                        int nodeVal = i * col + j;
                        int nextVal = ni * col + nj;
                        // Merge the current node and the next node (if they are both land cells)
                        ds.merge(nodeVal, nextVal);
                    }
                }

                // Merge the current node with the rowStart virtual node if it is in the top row
                if (i == 0)      ds.merge(rowStart, nodeVal);

                // Merge the current node with the rowEnd virtual node if it is in the bottom row
                if (i == row - 1)  ds.merge(rowEnd, nodeVal);

                // Check if the rowStart virtual node and the rowEnd virtual node are connected,
                // indicating a path from top to bottom exists, then return 'c' (current day)            
                if (ds.connected(rowStart, rowEnd))  return c;

            }
            // No path from top to bottom exists, so return '0' (first Day)
            return 0;
        }
    };
}
