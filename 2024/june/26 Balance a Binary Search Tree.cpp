// 1382. Balance a Binary Search Tree
// https://leetcode.com/problems/balance-a-binary-search-tree

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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        return buildBalancedBST(inorder, 0 , inorder.size() - 1);
    }

private:
    void inorderTraversal(
        TreeNode* root,
        vector<int>& inorder
    ) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    TreeNode* buildBalancedBST(
        const vector<int>& inorder,
        int start,
        int end
    ) {
        if (start > end) return nullptr;

        int mid = start +(end - start)/2;
        TreeNode* left = buildBalancedBST(inorder, start, mid - 1);
        TreeNode* right = buildBalancedBST(inorder, mid + 1, end);
        return new TreeNode(
            inorder[mid],
            left,
            right
        );
    }
};
