/*
62. Unique Paths
https://leetcode.com/problems/unique-paths/

There is a robot on an m x n grid. The robot is initially located at the top-left corner
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take
to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.


Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Constraints:

1 <= m, n <= 100

*/

using namespace std;

#include <vector>
#include <iostream>

namespace {
	class Solution {
	public:
		int uniquePaths(int m, int n) {
			// if source and destination are same
			// there in only one path
			if (m == n) return 1;

			// initialize dp[m][n] with '1'
			vector<vector<int>> dp(
				m, 
				vector<int>(n, 1));

			for (int i = 1; i < m; ++i) {
				for (int j = 1; j < n; ++j) {
					// sum of paths from right & down cells
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}

			return dp[m - 1][n - 1];
		}
	};
}  // namesapce


void testUniquePaths() {
	// Input: m = 3, n = 7
	// Output: 28
	cout << "Unique Path: " << Solution().uniquePaths(3, 7) << endl;

	// Input: m = 3, n = 2
	// Output: 3
	cout << "Unique Path: " << Solution().uniquePaths(3, 2) << endl;
}  // namespace
