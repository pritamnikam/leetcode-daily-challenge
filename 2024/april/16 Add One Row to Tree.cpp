// 623. Add One Row to Tree
// https://leetcode.com/problems/add-one-row-to-tree

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* t = new TreeNode(val);
            t->left = root;
            return t;
        }

        insert(root, val, depth, 1);
        return root;
    }

private:
    void insert(
        TreeNode* node,
        int val,
        int depth,
        int currentDepth
    ) {
        if (node == nullptr) return;

        if (depth -1 == currentDepth) {
            TreeNode* l = node->left;
            TreeNode* r = node->right;

            node->left = new TreeNode(val);
            node->right = new TreeNode(val);
            node->left->left = l;
            node->right->right = r;
            return;
        }

        insert(node->left, val, depth, 1 + currentDepth);
        insert(node->right, val, depth, 1 + currentDepth);
    }
};
