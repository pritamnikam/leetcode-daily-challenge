/*
576. Out of Boundary Paths
https://leetcode.com/problems/out-of-boundary-paths/

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn].
You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the
grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the
ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12

Constraints:
1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n

*/

namespace {
class Solution {
    const int M = 1000000007;
    unordered_map<string, int> memo;
    
public:
    int findPaths(int m, int n, int maxMove,
                  int startRow, int startColumn) {
        // ball out of the grid boundary
        if (startRow == m or
            startColumn == n or
            startRow < 0 or
            startColumn < 0) {
            return 1;
        }
        
        // exhausted all moves
        if (maxMove == 0) {
            return 0;
        }
        
        string key = to_string(startRow) + "-" + 
                     to_string(startColumn) + "-" + 
                     to_string(maxMove);
        
        if (memo.count(key)) 
            return memo[key];
        
        return memo[key] =
            (findPaths(m,n,maxMove-1, startRow + 1, startColumn) % M +
             findPaths(m,n,maxMove-1, startRow - 1, startColumn) % M +
             findPaths(m,n,maxMove-1, startRow, startColumn + 1) % M +
             findPaths(m,n,maxMove-1, startRow, startColumn - 1) % M) % M;
    }
};
}
