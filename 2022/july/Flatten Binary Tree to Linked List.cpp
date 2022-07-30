/*
Flatten Binary Tree to Linked List
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points
to the next node in the list and the left child pointer is always null.

The "linked list" should be in the same order as a pre-order traversal of the binary tree.


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]


Input: root = []
Output: []

Input: root = [0]
Output: [0]

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100


Follow up: Can you flatten the tree in-place (with O(1) extra space)?
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
        void flatten(TreeNode* root) {
            root = flattenTree(root);
        }


        TreeNode* flattenTree(TreeNode* root) {
            if (root == nullptr) return nullptr;
            if (root->left == nullptr && root->right == nullptr) return root;

            TreeNode* leftTail = flattenTree(root->left);
            TreeNode* rightTail = flattenTree(root->right);

            if (leftTail) {
                leftTail->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }

            return rightTail == nullptr ? leftTail : rightTail;
        }


        void flattenIterative(TreeNode* root) {
            if (root == nullptr) return;
            if (root->left == nullptr && root->right == nullptr) return;

            TreeNode* current = root;
            while (current) {
                // If the node has a left child
                if (current->left) {

                    // Find the rightmost node
                    TreeNode* rightMost = current->left;
                    while (rightMost->right) {
                        rightMost = rightMost->right;
                    }

                    // rewire the connections
                    rightMost->right = current->right;
                    current->right = current->left;
                    current->left = nullptr;
                }

                // move forward
                current = current->right;
            }

        }

    };
} // namespace