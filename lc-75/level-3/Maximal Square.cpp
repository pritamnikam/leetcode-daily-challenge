/*

221. Maximal Square
https://leetcode.com/problems/maximal-square/

Given an m x n binary matrix filled with 0's and 1's, find the largest square 
containing only 1's and return its area.

Input: matrix = [['1','0','1','0','0'],['1','0','1','1','1'],['1','1','1','1','1'],['1','0','0','1','0']]
Output: 4

Input: matrix = [['0','1'],['1','0']]
Output: 1


Input: matrix = [['0']]
Output: 0

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.

*/


using namespace std;

#include <iostream>
#include <vector>
#include <queue>

namespace {
	class Solution {
	public:
		int maximalSquare(vector<vector<char>>& matrix) {
			int rows = matrix.size(),
				cols = rows > 0 ? matrix[0].size() : 0;

			vector<vector<int>> dp(
				rows + 1,
				vector<int>(cols + 1, 0)
			);

			int maxsqlen = 0;
			for (int i = 1; i <= rows; ++i) {
				for (int j = 1; j <= cols; ++j) {
					if (matrix[i - 1][j - 1] == '1') {
						dp[i][j] = 1 + min(
							min(dp[i - 1][j], dp[i][j - 1]),
							dp[i - 1][j - 1]);
						maxsqlen = max(maxsqlen, dp[i][j]);
					}
				}
			}

			return maxsqlen;
		}
	};
}

void testMaximalSquare() {
	vector<vector<char>> matrix =
		{ 
			{'1', '0', '1', '0', '0'},
			{'1', '0', '1', '1', '1'},
			{'1', '1', '1', '1', '1'},
			{'1', '0', '0', '1', '0'}
		};

	cout << "Maximal Square: " << Solution().maximalSquare(matrix) << endl;
}