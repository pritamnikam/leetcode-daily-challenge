/*
437. Path Sum III
https://leetcode.com/problems/path-sum-iii/

Given the root of a binary tree and an integer targetSum, return the number of paths where the 
sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards
(i.e., traveling only from parent nodes to child nodes).

Example 1:
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3

Constraints:
The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000

*/



using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>


namespace {
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
	};


	class Solution {
		int k;
		int count;
		unordered_map<int, int> prefixSumFreq;

	public:
		int pathSum(TreeNode* root, int targetSum) {
			k = targetSum;
			count = 0;
			preorder(root, 0);
			return count;
		}

		void preorder(TreeNode* node, int currentSum) {
			if (node == nullptr) return;

			// prefix sum
			currentSum += node->val;

			// Situation 1: root until leaf
			// here is the sum we're looking for
			if (currentSum == k) ++count;

			// Situation 2: non-root and non-leaf
			// number of times the curr_sum − k has occured already, 
			// determines the number of times a path with sum k 
			// has occured upto the current node
			if (prefixSumFreq.count(currentSum - k)) {
				count += prefixSumFreq[currentSum];
			}

			// add the current sum into hashmap
			// to use it during the child nodes processing
			prefixSumFreq[currentSum] += 1;

			// process sub-tree
			preorder(node->left, currentSum);
			preorder(node->right, currentSum);

			// remove the current sum from the hashmap
			// in order not to use it during 
			// the parallel subtree processing
			prefixSumFreq[currentSum] -= 1;
		}
	};
}  // namespace


void testPathSumIII() {
/*
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
*/
	
	TreeNode left; left.val = 5, left.left = nullptr, left.right = nullptr;
	TreeNode right; left.val = -3, left.left = nullptr, left.right = nullptr;
	TreeNode root; root.val = 10, root.left = &left, root.right = &right;


}