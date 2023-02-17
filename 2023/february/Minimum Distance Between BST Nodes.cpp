/*
783. Minimum Distance Between BST Nodes
https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

Given the root of a Binary Search Tree (BST), return the minimum difference between the 
values of any two different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1

Constraints:
The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105


Note: This question is the same as 
530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/


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
		int minDiffInBST(TreeNode* root) {
            if (root == nullptr)
                return 0;

            vector<int> values;
            Inorder(root, values);

            int result = INT_MAX;
            for (int i = 1; i < values.size(); ++i) {
                result = min(result, values[i] - values[i - 1]);
            }

            return result;
		}

    private:
        void Inorder(TreeNode* root, vector<int>& values) {
            if (root == nullptr)
                return;

            Inorder(root->left, values);
            values.push_back(root->val);
            Inorder(root->right, values);
        }
	};
}  // namespace


void testMinimumDistanceBeteenBSTNodes() {
    // Input: root = [4,2,6,1,3] | Output: 1
    TreeNode one(1), two(2), three(3), four(4), six(6);
    four.left = &two; four.right = &six;
    two.left = &one, two.right = &three;
    cout << "Minimum Distance Between BST Nodes: " << Solution().minDiffInBST(&four) << endl;
}
