/*
222. Count Complete Tree Nodes
https://leetcode.com/problems/count-complete-tree-nodes/

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in
a complete binary tree, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [1]
Output: 1

Constraints:
The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.

*/

using namespace std;

#include <iostream>

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
	public:
		int countNodes(TreeNode* root) {
			// if the tree is empty
			if (root == nullptr)
				return 0;

			int d = computeDepth(root);

			// if the tree contains 1 node
			if (d == 0) return 1;

			// Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
			// Perform binary search to check how many nodes exist.
			int left = 1,
				right = (int)(1 << d) - 1;

			int pivot;
			while (left <= right) {
				pivot = left + (right - left) / 2;
				if (exists(pivot, d, root))
					left = pivot + 1;

				else
					right = pivot - 1;
			}

			// The tree contains 2**d - 1 nodes on the first (d - 1) levels
			// and left nodes on the last level.
			return (int)(1 << d) - 1 + left;
		}

	private:
		// Return tree depth in O(d) time.
		int computeDepth(TreeNode* node) {
			int d = 0;
			while (node->left != nullptr) {
				node = node->left;
				++d;
			}
			return d;
		}

		// Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
		// Return True if last level node idx exists. 
		// Binary search with O(d) complexity.
		bool exists(int idx, int d, TreeNode* node) {
			int left = 0, 
				right = (int)(1 << d) - 1;

			int pivot;
			for (int i = 0; i < d; ++i) {
				pivot = left + (right - left) / 2;

				if (idx <= pivot) {
					node = node->left;
					right = pivot;
				}
				else {
					node = node->right;
					left = pivot + 1;
				}
			}
			return node != nullptr;
		}
	};
 

}  // namespace

void testCountCompleteTreeNodes() {
	// Input: root = [1,2,3,4,5,6]
	// Output: 6

	TreeNode one(1), two(2), three(3), four(4), five(5), six(6);
	one.left = &two, one.right = &three, 
	two.left = &four, two.right = &five,
	three.left = &six;

	cout << "Count Complete Tree Nodes: " << Solution().countNodes(&one) << endl;
}
