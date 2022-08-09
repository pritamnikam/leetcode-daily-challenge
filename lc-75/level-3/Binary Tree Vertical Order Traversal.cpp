/*
314. Binary Tree Vertical Order Traversal
https://leetcode.com/problems/binary-tree-vertical-order-traversal/

Given the root of a binary tree, return the vertical order traversal of its nodes' values.
(i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]

Example 2:
Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]


Example 3:
Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
Output: [[4],[9,5],[3,0,1],[8,2],[7]]

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

namespace {
	/**
	 * Definition for a binary tree node.
	 */
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};

	class Solution {
	public:
		// treat binary tree as a 2-D matrix
		vector<vector<int>> verticalOrder(TreeNode* root) {
			if (root == nullptr) return {};

			unordered_map<int, vector<int>> columnMap;
			queue<pair<TreeNode*, int>> queue;


			queue.push({ root, 0 });
			int minColumn = 0, maxColumn = 0;

			while (!queue.empty()) {
				pair<TreeNode*, int> current = queue.front();
				queue.pop();

				TreeNode* node = current.first;
				int column = current.second;
				minColumn = min(minColumn, column), 
				maxColumn = max(maxColumn, column);

				columnMap[column].push_back(node->val);
				if (node->left) queue.push({ node->left, column - 1 });
				if (node->right) queue.push({ node->right, column + 1 });
			}


			vector<vector<int>> result;
			for (int i = minColumn; i <= maxColumn; ++i) {
				result.push_back(columnMap[i]);
			}

			return result;
		}
	};

} // namespace


void testBinaryTreeVerticalOrderTraversal() {
	/*
		Input: root = [3,9,20,null,null,15,7]
		Output: [[9],[3,15],[20],[7]]
	*/


	TreeNode three(3), nine(9), twenty(20), fifteen(15), seven(7);
	three.left = &nine, three.right = &twenty;
	twenty.left = &fifteen, twenty.right = &seven;

	vector<vector<int>> result = Solution().verticalOrder(&three);
}
