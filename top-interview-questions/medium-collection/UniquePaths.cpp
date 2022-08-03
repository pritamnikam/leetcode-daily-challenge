/*
Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move 
either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to 
reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: m = 3, n = 7
Output: 28


Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

*/

using namespace std;
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // if src & dst are same
        // only one possible path
        if (m == 1 && n == 1) {
            return 1;
        }

        // initialize dp[m][n] with '1'
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // for all rows
        for (int i = 1; i < m; ++i) {
            // for all columns
            for (int j = 1; j < n; ++j) {
                // sum of paths from right & down cells
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

    int uniquePaths2(int m, int n) {

        vector<vector<int>> paths(n, vector<int>(m));

        for (int c = 0; c < m; ++c)
            paths[n - 1][c] = 1;

        for (int r = 0; r < n; ++r)
            paths[r][m-1] = 1;

        for (int r = n - 2; r >= 0; --r) {
            for (int c = m - 2; c >= 0; --c) {
                paths[r][c] = paths[r][c + 1] + paths[r + 1][c];
            }
        }

        return paths[0][0];
    }

    vector<vector<int>> dp;
    int uniquePathsUtil(int m, int n) {
        if (n == 1 || m == 1) return 1;
        if (dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = uniquePathsUtil(m - 1, n) + uniquePathsUtil(m, n - 1);
    }

    int uniquePaths3(int m, int n) {
        dp.clear();
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return uniquePathsUtil(m, n);
    }
};