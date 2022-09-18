/*
606. Construct String from Binary Tree
https://leetcode.com/problems/construct-string-from-binary-tree/

Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.



Example 1:


Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"
Example 2:


Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.


Constraints:

The number of nodes in the tree is in the range [1, 104].
-1000 <= Node.val <= 1000

*/
#include <iostream>
#include <string>

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
		string tree2str(TreeNode* root) {
			if (root == nullptr) return string();

			if (root->left == nullptr and root->right == nullptr) {
				return to_string(root->val);
			}

			if (root->right == nullptr) {
				return to_string(root->val)
					+ "(" + tree2str(root->left) + ")";
			}

			return to_string(root->val)
				+ "(" + tree2str(root->left) + ")"
				+ "(" + tree2str(root->right) + ")";
		}
	};
}

void testConstructStringFromBinaryTree() {
	TreeNode one(1), two(2), three(3), four(4);
	one.left = &two, one.right = &three, two.left = &four;
	cout << "Construct String from Binary Tree: " << Solution().tree2str(&one) << endl;
}