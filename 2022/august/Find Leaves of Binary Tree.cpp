/*
366. Find Leaves of Binary Tree
https://leetcode.com/problems/find-leaves-of-binary-tree/

Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.

Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each
level it does not matter the order on which elements are returned.

Example 2:

Input: root = [1]
Output: [[1]]

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100


*/

using namespace std;
#include <vector>
#include <unordered_set>
namespace {

	 // Definition for a binary tree node.
	 struct TreeNode {
		 int val;
		 TreeNode *left;
		 TreeNode *right;
		 TreeNode() : val(0), left(nullptr), right(nullptr) {}
		 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	 };

	class Solution {
	public:
		vector<vector<int>> findLeaves(TreeNode* root) {
			if (root == nullptr) return {};

			vector<vector<int>> result;
			vector<int> leaves;
			do {
				leaves.clear();
				findLeaves(root, leaves);
				if (leaves.empty()) break;
				result.push_back(leaves);
			} while (true);

			return result;
		}


	private:
		void findLeaves(TreeNode* root, vector<int>& leaves) {
			if (root == nullptr || removed.count(root)) return;

			if (isLeaf(root)) {
				removed.insert(root);
				leaves.push_back(root->val);
			}

			findLeaves(root->left, leaves);
			findLeaves(root->right, leaves);
		}

		bool isLeaf(TreeNode* root) {
			return	(!root->left or removed.count(root->left)) and 
					(!root->right or removed.count(root->right));
		}

		unordered_set<TreeNode*> removed;
	};
}  // namespace