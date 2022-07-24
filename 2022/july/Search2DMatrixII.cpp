/*
240. Search a 2D Matrix II
https://leetcode.com/problems/search-a-2d-matrix-ii/

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false


Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109

*/


using namespace std;

#include <iostream>
#include <vector>

namespace {
	class Solution {

		bool binarySearch(vector<int> arr, int target) {
			int l = 0, r = arr.size() - 1;
			while (l <= r) {
				int mid = l + (r - l) / 2; // overflow;
				if (arr[mid] == target) return true;
				if (arr[mid] < target) l = mid + 1;
				else r = mid - 1;
			}
			return false;
		}

	public:
		// O(log(n)+log(n−1)+log(n−2)+…+log(1)) -> O(log(n!))
		bool searchMatrix2BS(vector<vector<int>>& matrix, int target) {
			for (vector<int>& arr : matrix) {
				if (binarySearch(arr, target)) return true;
			}
			return false;
		}

		// O(m + n)
		bool searchMatrix2(vector<vector<int>>& matrix, int target) {
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

void testSearch2DMatrixII() {
	vector < vector<int>> matrix = { {1, 4, 7, 11, 15},
	{2, 5, 8, 12, 19},{3, 6, 9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30} };
	int target = 5;


	cout << "Search a 2D Matrix II: " << Solution().searchMatrix2(matrix, target) << endl;
}
