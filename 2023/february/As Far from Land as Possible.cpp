/*
1162. As Far from Land as Possible
https://leetcode.com/problems/as-far-from-land-as-possible/description/

Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.



Example 1:


Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
Example 2:


Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.


Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1

*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

namespace {
    class Solution {

        vector<vector<int>> directions = { {1,0},{-1,0}, {0, 1}, {0, -1} };

        bool isValid(vector<vector<int>>& grid, int i, int j) {
            return (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size());
        }

    public:
        int maxDistance(vector<vector<int>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();

            queue<pair<int, int>> queue;

            // 0 represents water and 1 represents land
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (grid[i][j] == 1)
                        queue.push(make_pair(i, j));
                }
            }

            // all are either 0s or 1s
            if (queue.empty() || queue.size() == rows * cols)
                return -1;

            int count = -1;
            while (!queue.empty()) {
                int levelSize = queue.size();
                for (int i = 0; i < levelSize; ++i) {
                    pair<int, int> front = queue.front();
                    queue.pop();

                    for (auto it : directions) {
                        int x = it[0] + front.first;
                        int y = it[1] + front.second;

                        if (isValid(grid, x, y) && grid[x][y] == 0) {
                            grid[x][y] = 1;
                            queue.push(make_pair(x, y));
                        }
                    }
                }

                ++count;
            }

            return count;
        }
    };
} // namespace

void testAsFarFromLandAsPossible() {
    // Input: grid = [[1,0,1],[0,0,0],[1,0,1]], Output: 2
    vector<vector<int>> grid = { {1, 0, 1},{0, 0, 0},{1, 0, 1} };
    cout << "As Far from Land as Possible: " << Solution().maxDistance(grid) << endl;
}
