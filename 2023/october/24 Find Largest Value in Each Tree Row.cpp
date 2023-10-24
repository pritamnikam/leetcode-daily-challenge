// 515. Find Largest Value in Each Tree Row.cpp
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};

        queue<TreeNode*> queue;
        queue.push(root);

        vector<int> answer;

        while (!queue.empty()) {
            int len = queue.size();
            int currMax = INT_MIN;

            for (int i = 0; i < len; i++) {
                TreeNode* t = queue.front();
                queue.pop();
                currMax = max(currMax, t->val);

                if (t->left) queue.push(t->left);
                if (t->right) queue.push(t->right);
            }
            answer.push_back(currMax);
        }

        return answer;
    }
};
