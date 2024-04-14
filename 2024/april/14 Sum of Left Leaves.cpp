// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        return sumOfLeftLeaves(root, false);
    }

private:
int sumOfLeftLeaves(
    TreeNode* root,
    bool isLeft
) {
    if (root == nullptr) return 0;

    if (
        root->left == nullptr &&
        root->right == nullptr &&
        isLeft
    ) {
        return root->val;
    }

    int leftSum = 0;
    if (root->left) {
        leftSum = sumOfLeftLeaves(root->left, true);
    }

    int rightSum = 0;
    if (root->right) {
        rightSum = sumOfLeftLeaves(root->right, false);
    }
    return leftSum + rightSum;
}
};
