// 606. Construct String from Binary Tree
// https://leetcode.com/problems/construct-string-from-binary-tree/

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
    string tree2str(TreeNode* root) {
        string result;
        dfs(root, result);
        return result;
    }

    void dfs(TreeNode* node, string& str) {
        if (node == nullptr) return;

        str += to_string(node->val);
        if (node->left || node->right) {
            str += '(';
            dfs(node->left, str);
            str += ')';
        }

        if (node->right) {
            str += '(';
            dfs(node->right, str);
            str += ')';
        }
    }
};
