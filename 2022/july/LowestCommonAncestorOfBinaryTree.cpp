/*
236. Lowest Common Ancestor of a Binary Tree
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/


Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined
between two nodes p and q as the lowest node in T that has both p and q as descendants
(where we allow a node to be a descendant of itself).”

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


Input: root = [1,2], p = 1, q = 2
Output: 1

*/

using namespace std;

#include <iostream>
#include <vector>

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
		TreeNode* lowestCommonAncestor(TreeNode* root,
									   TreeNode* p,
									   TreeNode* q) {
			// Base cases:
			// 1. root is null
			if (root == nullptr)
				return nullptr;

			// 2. either of p or q are root, then root will be LCA for that node
			if (root == p || root == q)
				return root;

			// search left or right of the root
			TreeNode* left_lca = lowestCommonAncestor(root->left, p, q);
			TreeNode* right_lca = lowestCommonAncestor(root->right, p, q);

			// if both returns non-null then each node present in left and right subtree
			// return root as our lca
			if (left_lca && right_lca)
				return root;

			// otherwise: non-null will be our lca
			return (left_lca != nullptr) ? left_lca : right_lca;
		}
	};

} // namesapce

