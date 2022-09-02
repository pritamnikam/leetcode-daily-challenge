/*
637. Average of Levels in Binary Tree
https://leetcode.com/problems/average-of-levels-in-binary-tree/

Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. 
Answers within 10-5 of the actual answer will be accepted.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

Example 2:
Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]


Constraints:
The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
		vector<double> averageOfLevels(TreeNode* root) {
			if (root == nullptr) return  {};

			vector<double> result;
			queue<TreeNode*> queue;

			queue.push(root);

			while (!queue.empty()) {
				int size = queue.size();
				int levelSum = 0;
				for (int i = 0; i < size; ++i) {
					TreeNode* current = queue.front();
					queue.pop();

					levelSum += current->val;

					if (current->left) queue.push(current->left);
					if (current->right) queue.push(current->right);
				}

				result.push_back((double)levelSum / size);
			}

			return result;
		}
	};
} // namespace 

void testAverageOfLevelsInBinaryTree() {
	// root = [3,9,20,null,null,15,7]
	TreeNode root(3, new TreeNode(9), new TreeNode(20));
	root.right->left = new TreeNode(15);
	root.right->right = new TreeNode(7);

	vector<double> result = Solution().averageOfLevels(&root);
}
