/*
378. Kth Smallest Element in a Sorted Matrix
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

Given an n x n matrix where each of the rows and columns is sorted in ascending order, 
return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).



Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5


Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2


Follow up:

Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

namespace {
	// data structure to hold, number mapping to row and col in matrix
	struct Entry {
		int row;
		int col;
		int value;
	};
	

	struct Compare {
		bool operator()(const Entry& a, const Entry& b) {
			return a.value > b.value;
		}
	};

	class Solution {
	public:
		int kthSmallest(vector<vector<int>>& matrix, int k) {
			int result = -1;
			priority_queue<Entry, vector<Entry>, Compare> minHeap;

			int rows = matrix.size(), 
				cols = matrix[0].size();

			for (int i = 0; i < rows and i < k; ++i) {
				minHeap.push(
					// row, col, value
					{ i, 0, matrix[i][0] }
				);
			}

			int count = 0;
			while (!minHeap.empty()) {
				Entry entry = minHeap.top();
				minHeap.pop();

				result = entry.value;

				++count;
				if (count == k)
					break;

				entry.col++;
				if (entry.col < cols) {
					entry.value = matrix[entry.row][entry.col];
					minHeap.push(entry);
				}
			}

			return result;
		}
	};
} // namespace

void testFindKSmallest() {
	vector<vector<int>> matrix = { {1, 5, 9},{10, 11, 13},{12, 13, 15} };
	int k = 8;

	cout << "Kth Smallest Element in a Sorted Matrix: " << Solution().kthSmallest(matrix, k) << endl;
}
