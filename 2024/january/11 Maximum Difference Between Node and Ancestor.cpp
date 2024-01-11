// 1026. Maximum Difference Between Node and Ancestor
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return maxAncestorDiff(root, root->val, root->val);
    }

private:
    int maxAncestorDiff(TreeNode* node, int curMax, int curMin) {
        // if encounter leaves, return the max-min along the path
        if (node == nullptr) {
            return curMax - curMin;
        }

        // pre-order:
        
        // else, update max and min
        // and return the max of left and right subtrees
        curMax = max(curMax, node->val);
        curMin = min(curMin, node->val);

        int left = maxAncestorDiff(node->left, curMax, curMin);
        int right = maxAncestorDiff(node->right, curMax, curMin);
        return max(left, right);
    }
};
