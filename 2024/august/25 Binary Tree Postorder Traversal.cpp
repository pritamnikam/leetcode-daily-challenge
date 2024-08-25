// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> output;
        helper(root, output);
        return output;
    }

private:
    void helper(TreeNode* root, vector<int>& output) {
        if (root == nullptr) {
            return;
        }

        if (root->left) {
            helper(root->left, output);
        }
        if (root->right) {
            helper(root->right, output);
        }

        output.push_back(root->val);
    }
};
