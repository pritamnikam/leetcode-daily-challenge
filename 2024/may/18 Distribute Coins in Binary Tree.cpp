// 979. Distribute Coins in Binary Tree
// https://leetcode.com/problems/distribute-coins-in-binary-tree/

using namespace std;

#include <iostream>

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
        int distributeCoins(TreeNode* root) {
            moves = 0;
            dfs(root);
            return moves;
        }

    private:
        int moves = 0;

        int dfs(TreeNode* root) {
            if (root == nullptr) return 0;

            // Calculate the left & right subtree coins requirements
            int leftCoins = dfs(root->left);
            int rightCoins = dfs(root->right);

            // add to the total
            moves += abs(leftCoins) + abs(rightCoins);

            // number of coins root has available to exchange
            return (root->val - 1) + leftCoins + rightCoins;
        }
    };

}