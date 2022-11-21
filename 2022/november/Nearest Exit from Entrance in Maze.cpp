/*
1926. Nearest Exit from Entrance in Maze
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

You are given an m x n matrix maze (0-indexed) with
 - empty cells (represented as '.') and 
 - walls (represented as '+'). 
 
 You are also given the entrance of the maze, 
 where entrance = [entrancerow, entrancecol] 
 denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. 
You cannot step into a cell with a wall, and you cannot step outside the maze. 

Your goal is to find the nearest exit from the entrance. 
An exit is defined as an empty cell that is at the border of the maze. 
The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, 
or -1 if no such path exists.

Example 1:
Input: maze = [['+','+','.','+'],['.','.','.','+'],['+','+','+','.']], entrance = [1,2]
Output: 1
Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.

Example 2:
Input: maze = [['+','+','+'],['.','.','.'],['+','+','+']], entrance = [1,0]
Output: 2
Explanation: There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.

Example 3:
Input: maze = [['.','+']], entrance = [0,0]
Output: -1
Explanation: There are no exits in this maze.


Constraints:
maze.length == m
maze[i].length == n
1 <= m, n <= 100
maze[i][j] is either '.' or '+'.
entrance.length == 2
0 <= entrancerow < m
0 <= entrancecol < n
entrance will always be an empty cell.

*/

using namespace std;

#include <queue>
#include <vector>
#include <iostream>

namespace {
    class Solution {
        // up, down, left, or right
        vector<pair<int, int>> dirs = { 
            {1, 0}, {-1, 0}, {0, 1}, {0, -1} 
        };

    public:
        int nearestExit(
            vector<vector<char>>& maze, 
            vector<int>& entrance) {

            int rows = maze.size(), 
                cols = maze[0].size();            

            // Mark the entrance as visited since its not a exit.
            int startRow = entrance[0], 
                startCol = entrance[1];

            maze[startRow][startCol] = '+';

            // Start BFS from the entrance, and use a queue `queue` to store all 
            // the cells to be visited.
            queue<vector<int>> queue;
            queue.push({ startRow, startCol, 0 });

            while (!queue.empty()) {
                auto cur = queue.front();
                int currRow = cur[0],
                    currCol = cur[1],
                    currDistance = cur[2];

                queue.pop();

                // For the current cell, check its four neighbor cells.
                for (auto dir : dirs) {
                    int nextRow = currRow + dir.first, 
                        nextCol = currCol + dir.second;

                    // If there exists an unvisited empty neighbor:
                    if (0 <= nextRow 
                        && nextRow < rows 
                        && 0 <= nextCol 
                        && nextCol < cols
                        && maze[nextRow][nextCol] == '.') {

                        // If this empty cell is an exit, return distance + 1.
                        if (nextRow == 0 
                            || nextRow == rows - 1 
                            || nextCol == 0 
                            || nextCol == cols - 1){
                            return currDistance + 1;
                        }

                        // Otherwise, add this cell to 'queue' and mark it as visited.
                        maze[nextRow][nextCol] = '+';
                        queue.push({ nextRow, nextCol, currDistance + 1 });
                    }
                }
            }

            // If we finish iterating without finding an exit, return -1.
            return -1;
        }
    };
} // namespace


void testNearestExitFromEntranceInMaze() {
    vector<vector<char>> maze = {
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'}
    };

    vector<int> entrance = { 1, 2 };

    cout << "Nearest Exit from Entrance in Maze: " << Solution().nearestExit(maze, entrance) << endl;
}
