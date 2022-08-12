/*
235. Lowest Common Ancestor of a Binary Search Tree
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes
p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant
of itself).”

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.


Input: root = [2,1], p = 2, q = 1
Output: 2

Constraints:
The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.

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
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if (root == nullptr) return nullptr;

			if (root->val >= p->val and root->val >= q->val)
				return lowestCommonAncestor(root->left, p, q);

			if (root->val <= p->val and root->val <= q->val)
				return lowestCommonAncestor(root->right, p, q);

			return root;
		}
	};
}


void testLowestCommonAncestor() {
	/*
		Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
		Output: 6
	*/

	TreeNode root(
		6,
		new TreeNode(
			2,
			new TreeNode(0),
			new TreeNode(
				4,
				new TreeNode(3),
				new TreeNode(5)
			)
		),
		new TreeNode(
			8,
			new TreeNode(7),
			new TreeNode(9)
		)
	);

	TreeNode* p = root.left,
			 *q = root.right;

	cout << "Lowest Common Ancestor of a Binary Search Tree: " << Solution().lowestCommonAncestor(&root, p, q)->val << endl;

}
