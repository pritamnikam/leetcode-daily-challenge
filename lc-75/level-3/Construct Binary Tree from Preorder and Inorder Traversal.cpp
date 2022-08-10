/*
105. Construct Binary Tree from Preorder and Inorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a 
binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Input: preorder = [-1], inorder = [-1]
Output: [-1]


Constraints:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.


Algorithm:
	1. Build a hashmap |inorderIndexMap| to record the relation of value -> index for inorder, so that we can find the position of root in constant time.
	2. Initialize an integer variable preorderIndex to keep track of the element that will be used to construct the root.
	3. Implement the recursion function arrayToTree which takes a range of inorder and returns the constructed binary tree:
		a. if the range is empty, return null;
		b. initialize the root with preorder[preorderIndex] and then increment preorderIndex;
		c. recursively use the left and right portions of inorder to construct the left and right subtrees.
	4. Simply call the recursion function with the entire range of inorder.
*/


using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

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
		// keep track of the element that will be used to construct the root
		int preorderIndex;

		// record the relation of value -> index for inorder.
		unordered_map<int, int> inorderIndexMap;

		TreeNode* buildTree(vector<int>& preorder, int left, int right) {
			if (left > right) return nullptr;

			int rootValue = preorder[preorderIndex++];
			TreeNode* t = new TreeNode(rootValue);
			t->left = buildTree(preorder, left, inorderIndexMap[rootValue] - 1);
			t->right = buildTree(preorder, inorderIndexMap[rootValue] + 1, right);
			return t;
		}

	public:
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			// corner cases
			if (preorder.empty() ||
				inorder.empty() ||
				preorder.size() != inorder.size()) {
				return  nullptr;
			}

			preorderIndex = 0;
			for (int i = 0; i < inorder.size(); ++i) {
				inorderIndexMap[inorder[i]] = i;
			}

			return buildTree(preorder, 0, preorder.size() - 1);
		}
	};
} // namespace

void testConstructBinaryTreeFromPreorderAndInorderTraversal() {
	/*
		Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
		Output: [3,9,20,null,null,15,7]
	*/

	vector<int> preorder = { 3, 9, 20, 15, 7 }, inorder = { 9, 3, 15, 20, 7 };
	TreeNode* Output = Solution().buildTree(preorder, inorder);
}
