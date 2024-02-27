// 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree

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
    int diameterOfBinaryTree(TreeNode* root) {
        int treeDiameter = 0;
        calculateHeight(root, treeDiameter);
        return treeDiameter;
    }

private:
    int calculateHeight(TreeNode* root, int& treeDiameter) {
        if (root == nullptr) {
            return 0;
        }

        int l = calculateHeight(root->left, treeDiameter);
        int r = calculateHeight(root->right, treeDiameter);

        treeDiameter = max(treeDiameter, l + r);
        return 1 + max(l, r);
    }
};
