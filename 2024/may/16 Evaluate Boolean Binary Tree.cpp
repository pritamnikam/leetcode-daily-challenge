// 2331. Evaluate Boolean Binary Tree
// https://leetcode.com/problems/evaluate-boolean-binary-tree

namespace {
    /**
     * Definition for a binary tree node.
     */ 
     struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };
     
     class Solution {
     public:
         bool evaluateTree(TreeNode* root) {
             if (root == nullptr) return false;

             bool leftResult = evaluateTree(root->left);
             bool rightResult = evaluateTree(root->right);

             if (root->left == nullptr && root->right == nullptr) {
                 return root->val == 1;
             }

             if (root->val == 2) return leftResult or rightResult;
             return leftResult and rightResult;
         }
     };
}