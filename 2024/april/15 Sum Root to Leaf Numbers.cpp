// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers


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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sumNumbers(root, sum, 0);
        return sum;
    }

private:
    void sumNumbers(
        TreeNode* node,
        int& sum,
        int currentSum
    ) {
        if (node == nullptr) {
            return;
        }

        int temp = currentSum;
        currentSum = currentSum * 10 + node->val;

        if (
            node->left == nullptr &&
            node->right == nullptr
        ) {
            sum += currentSum;
        }
        sumNumbers(node->left, sum, currentSum);
        sumNumbers(node->right, sum, currentSum);
        currentSum = temp;
    }
};
