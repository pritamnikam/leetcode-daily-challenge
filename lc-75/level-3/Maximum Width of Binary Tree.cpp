/*
662. Maximum Width of Binary Tree
https://leetcode.com/problems/maximum-width-of-binary-tree/

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes 
(the leftmost and rightmost non-null nodes), where the null nodes between the 
end-nodes that would be present in a complete binary tree extending down to
that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).

Constraints:
The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100


*/


using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

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
		int widthOfBinaryTree(TreeNode* root) {
			int minimum = 0, maximum = 0;

			queue<pair<TreeNode*, pair<int, int>>> queue;
			queue.push({ root, {0, 0} });

			while (!queue.empty()) {
				auto current = queue.front();
				queue.pop();

				TreeNode* node = current.first;
				auto dist = current.second;

				minimum = min(minimum, dist.first);
				maximum = max(maximum, dist.second);

				if (node->left) {
					queue.push({ node->left, {dist.first - 1, dist.second} });
				}

				if (node->right) {
					queue.push({ node->right, {dist.first, dist.second + 1} });
				}
			}

			return maximum - minimum;
		}
	};

} // namespace

void testWidthOfBinaryTree() {
	/*
		Input: root = [1, 3, 2, 5, 3, null, 9]
		Output : 4
	*/

	TreeNode root(
		1,
		new TreeNode(3, new TreeNode(5), new TreeNode(3)),
		new TreeNode(2, nullptr, new TreeNode(9))
	);

	cout << "Maximum Width of Binary Tree: " << Solution().widthOfBinaryTree(&root) << endl;
}
