/*
653. Two Sum IV - Input is a BST
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

Given the root of a Binary Search Tree and a target number k, 
return true if there exist two elements in the BST such that
their sum is equal to the given target.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105

*/

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
        bool findTarget(TreeNode* root, int k) {
            return findTarget(root, root, k);
        }

    private:
        bool findTarget(TreeNode* root, TreeNode* cur, int k) {
            if (cur == nullptr) return false;

            // binary search |k - cur->val|
            return search(root, cur, k - cur->val)
                || findTarget(root, cur->left, k)
                || findTarget(root, cur->right, k);
        }

        bool search(TreeNode* root, TreeNode* cur, int k) {
            if (root == nullptr)
                return false;

            if (root->val > k) {
                // search in left sub tree
                return search(root->left, cur, k);
            }
            else if (root->val < k) {
                // search in right sub tree
                return search(root->right, cur, k);
            }

            return root != cur;
        }
    };
} // namespace
