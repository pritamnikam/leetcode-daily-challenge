/*
199. Binary Tree Right Side View
https://leetcode.com/problems/binary-tree-right-side-view/

Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.


*/


using namespace std;

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>

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
        vector<int> rightSideView(TreeNode* root) {
            if (root == nullptr)
                return vector<int>();

            vector<int> result;
            queue<TreeNode*> q;
            q.push(root);

            while (!q.empty()) {
                int levelSize = q.size();
                for (int i = 1; i <= levelSize; ++i) {
                    TreeNode* current = q.front();
                    q.pop();

                    if (i == levelSize)
                        result.emplace_back(current->val);

                    if (current->left) q.push(current->left);
                    if (current->right) q.push(current->right);
                }
            }

            return result;
        }
    };
}