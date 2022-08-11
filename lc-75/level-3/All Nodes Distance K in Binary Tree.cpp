/*
863. All Nodes Distance K in Binary Tree
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

Given the root of a binary tree, the value of a target node target, and an integer k, return an array
of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.


Input: root = [1], target = 1, k = 3
Output: []


Constraints:
The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000

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

		unordered_map<TreeNode*, TreeNode*> parents;
		
		// get parent nodes
		void setParents(TreeNode* node , TreeNode* parent) {
			if (node == nullptr || parents.count(node)) return;

			parents[node] = parent;
			setParents(node->left, node);
			setParents(node->right, node);
		}

	public:
		vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
			setParents(root, nullptr);

			// BFS
			unordered_set<TreeNode*> visited;
			queue<pair<TreeNode*, int>> queue;
			queue.push({target, 0});
			visited.insert(target);

			vector<int> result;
			while (!queue.empty()) {
				auto current = queue.front();
				queue.pop();

				TreeNode* node = current.first;
				int distance = current.second;

				if (distance == k) {
					result.push_back(node->val);
				}
				else {
					if (node->left &&
						!visited.count(node->left)) {
						visited.insert(node->left);
						queue.push({ node->left, 1 + distance });
					}

					if (node->right &&
						!visited.count(node->right)) {
						visited.insert(node->right);
						queue.push({ node->right, 1 + distance });
					}

					TreeNode* parent = parents[node];
					if (parent &&
						!visited.count(parent)) {
						visited.insert(parent);
						queue.push({ parent, 1 + distance });
					}
				}
			}

			return result;
		}
	};
} // namespsace

void testAllNodesDistanceKInBinaryTree() {
	// root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], target = 5, k = 2
	TreeNode root(3, 
				  new TreeNode(5), 
				  new TreeNode(1));

	root.left->left = new TreeNode(6);
	root.left->right = new TreeNode(2,
									new TreeNode(7),
									new TreeNode(4));

	root.right->left = new TreeNode(0);
	root.right->right = new TreeNode(8);

	TreeNode* target = root.left; 
	int k = 2;

	vector<int> result = Solution().distanceK(&root, target, k);
}
