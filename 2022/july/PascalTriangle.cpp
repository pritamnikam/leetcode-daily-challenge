/*
118. Pascal's Triangle
https://leetcode.com/problems/pascals-triangle/solution/

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:
1 <= numRows <= 30

*/

using namespace std;

#include <vector>
#include <iostream>

namespace {
	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			if (numRows == 0) return {};
			vector<vector<int>> result(numRows);
			result[0] = { 1 };

			for (int r = 1; r < numRows; ++r) {
				vector<int> currentRow;
				vector<int> previousRow = result[r-1];
				currentRow.push_back(1);

				for (int c = 1; c < previousRow.size(); ++c) {
					currentRow.push_back(previousRow[c - 1] + previousRow[c]);
				}

				currentRow.push_back(1);
				result[r] = currentRow;
			}
			return result;
		}
	};
}


void testPascalsTriangle() {
	vector<vector<int>> triangle = Solution().generate(5);

	triangle = Solution().generate(1);
}
