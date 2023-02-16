/*
104. Maximum Depth of Binary Tree
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2

Constraints:
The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100


*/

using namespace std;

#include <iostream>

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
        int maxDepth(TreeNode* root) {
            if (root == nullptr) return 0;

            int leftSubtreeDepth = 0, rightSubtreeDepth = 0;
            if (root->left) leftSubtreeDepth = maxDepth(root->left);
            if (root->right) rightSubtreeDepth = maxDepth(root->right);

            return 1 + max(leftSubtreeDepth, rightSubtreeDepth);
        }
    };
} // namespace

void testMaximumDepthOfBinaryTree() {
    // Input: root = [3,9,20,null,null,15,7] | Output: 3
    TreeNode three(3), nine(9), twenty(20), fifteen(15), seven(7);
    three.left = &nine; three.right = &twenty;
    twenty.left = &fifteen; twenty.right = &seven;

    cout << "Maximum Depth of Binary Tree: " << Solution().maxDepth(&three) << endl;
}
