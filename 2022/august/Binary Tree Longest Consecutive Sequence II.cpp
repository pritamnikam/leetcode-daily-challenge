/*
549. Binary Tree Longest Consecutive Sequence II
https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/

Given the root of a binary tree, return the length of the longest consecutive path in the tree.

A consecutive path is a path where the values of the consecutive nodes in the path differ by one. This path can be either increasing or decreasing.

For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid.
On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

Input: root = [1,2,3]
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].

Input: root = [2,1,3]
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-3 * 104 <= Node.val <= 3 * 104

*/

namespace {
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
    int maxLength;
    
public:
    int longestConsecutive(TreeNode* root) {
        maxLength = 0;
        dfs(root);
        return maxLength;
    }
    
    vector<int> dfs(TreeNode* node) {
        if (node == nullptr) return {0, 0};
        
        int inr = 1,
            dcr = 1;
        
        if (node->left != nullptr) {
            vector<int> left = dfs(node->left);
            
            if (node->val == node->left->val+1) {
                dcr = left[1] + 1;
            } else if (node->val == node->left->val-1) {
                inr = left[0] + 1;
            }
        }
        
        if (node->right != nullptr) {
            vector<int> right = dfs(node->right);
            
            if (node->val == node->right->val+1) {
                dcr = right[1] + 1;
            } else if (node->val == node->right->val-1) {
                inr = right[0] + 1;
            }
        }
        
        maxLength = max(maxLength, dcr + inr - 1);
        return {inr, dcr};
    }
};
}
