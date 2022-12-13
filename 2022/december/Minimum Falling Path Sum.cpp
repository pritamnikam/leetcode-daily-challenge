/*
931. Minimum Falling Path Sum
https://leetcode.com/problems/minimum-falling-path-sum/

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that 
is either directly below or diagonally left/right. Specifically, the next element from position 
(row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {

	class Solution {
	public:
		// 1. perform DFS on every cell in last row
		// 2. every cell is treated as nodes
		// 3. adjlist will hold: down, leftDown, rightDown cells
		int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();

            int answer = INT_MAX;

            // reverse order in rows -> bottom to the top
            // so that results will in first row
            for (int row = n - 2; row >= 0; row--) {
                for (int col = 0; col < m; col++) {
                    int down = INT_MAX,
                        leftDown = INT_MAX,
                        rightDown = INT_MAX;

                    down = matrix[row + 1][col];

                    if (col > 0)
                        leftDown = matrix[row + 1][col - 1];

                    if (col < m - 1)
                        rightDown = matrix[row + 1][col + 1];

                    matrix[row][col] += min( down, min(leftDown, rightDown));
                }
            }

            for (int col = 0; col < m; col++) {
                answer = min(answer, matrix[0][col]);
            }
            return answer;
		}
	};

} // namespace

void testMinimumFallingPathSum() {
	// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]], Output: 13

	vector<vector<int>> matrix = { {2, 1, 3},{6, 5, 4},{7, 8, 9} };
	cout << "Minimum Falling Path Sum: " << Solution().minFallingPathSum(matrix) << endl;
}
