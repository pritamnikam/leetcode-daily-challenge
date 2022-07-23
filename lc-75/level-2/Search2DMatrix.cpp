/*
74. Search a 2D Matrix
https://leetcode.com/problems/search-a-2d-matrix/

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
	class Solution {
	public:
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			int rows = matrix.size(), cols = matrix[0].size();
			int r = 0, c = cols - 1;

			while (r >= 0 && c >= 0 && r < rows && c < cols) {
				if (matrix[r][c] == target) return true;
				if (matrix[r][c] < target) ++r;
				else --c;
			}
			return false;
		}
	};
}

void testSearchMatrix() {
	vector<vector<int>> matrix = { {1, 3, 5, 7} ,{10, 11, 16, 20},{23, 30, 34, 60} };
	int target = 13;

	cout << "Search matrix: " << Solution().searchMatrix(matrix, target) << endl;
}
