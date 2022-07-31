/*
101. Symmetric Tree
https://leetcode.com/problems/symmetric-tree/

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

*/

using namespace std;
#include <iostream>

namespace {

    // Definition for a binary tree node.
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
        bool isSymmetric(TreeNode* root) {
            if (root == nullptr)
                return true;

            return isSymmetric(root->left, root->right);
        }

        bool isSymmetric(TreeNode* left, TreeNode* right) {
            if (left == nullptr && right == nullptr)
                return true;

            if (left == nullptr || right == nullptr)
                return false;

            if (left->val != right->val)
                return false;

            return isSymmetric(left->left, right->right) &&
                isSymmetric(left->right, right->left);
        }
    };
}