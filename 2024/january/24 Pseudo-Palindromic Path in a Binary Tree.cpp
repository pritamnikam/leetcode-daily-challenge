// 1457. Pseudo-Palindromic Path in a Binary Tree
// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/

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
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root, 0);
        return count;
    }

private:
    void preorder(TreeNode* root, int path) {
        if (root != nullptr) {
            //Compute the occurrence of each digit in the corresponding register
            path = path ^ (1 << root->val);
            
            //If it's a leaf node check if the path is pseudo-palindromic
            if (root->left == nullptr && root->right == nullptr) {
                // check if at most one digit has an odd frequency
                if ((path & (path - 1)) == 0) {
                    ++count;   
                }
            }
        
            preorder(root->left, path);
            preorder(root->right, path);
        }
    }

    int count = 0;
};
