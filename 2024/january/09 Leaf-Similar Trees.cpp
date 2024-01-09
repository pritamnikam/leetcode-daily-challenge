// 872. Leaf-Similar Trees
// https://leetcode.com/problems/leaf-similar-trees/

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        getLeaves(root1, l1);
        getLeaves(root2, l2);
        return l1 == l2;
    }

private:
    void getLeaves(TreeNode* root, vector<int>& leaves) {
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
        }
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
};
