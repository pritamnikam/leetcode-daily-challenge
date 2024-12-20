// 2415. reverse-odd-levels-of-binary-tree
// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/


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
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(
            root->left,
            root->right,
            0
        );
        return root;
    }

private:
    void dfs(
        TreeNode* left,
        TreeNode* right,
        int level
    ) {
        if (left == nullptr || right == nullptr) {
            return;
        }

        // if level is odd
        if (level % 2 == 0) {
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
        }

        dfs(left->left, right->right, level + 1);
        dfs(left->right, right->left, level + 1);
    }
};
