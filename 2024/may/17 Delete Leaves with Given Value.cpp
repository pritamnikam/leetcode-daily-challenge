// 1325. Delete Leaves with Given Value
// https://leetcode.com/problems/delete-leaves-with-a-given-value

namespace {
    /**
     * Definition for a binary tree node.
     */ 
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
        TreeNode* removeLeafNodes(TreeNode* root, int target) {
            // Post-order Traversal
            if (root == nullptr) {
                return nullptr;
            }

            root->left = removeLeafNodes(root->left, target);
            root->right = removeLeafNodes(root->right, target);

            // leaf node
            if (root->left == nullptr && root->right == nullptr && root->val == target) {
                // unlink the root
                return nullptr;
            }

            // keep it untouched
            return root;
        }
    };
 }