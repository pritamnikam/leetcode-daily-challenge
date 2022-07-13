/*
102. Binary Tree Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      if (root == nullptr) return {};
      
      vector<vector<int>> result;
      queue<TreeNode*> queue;
      queue.push(root);
      
      while(!queue.empty()) {
        int size = queue.size();        
        vector<int> level;
        for (int i = 0; i < size; ++i) {        
          TreeNode* current = queue.front();
          queue.pop();
          
          level.push_back(current->val);
          if (current->left) queue.push(current->left);
          if (current->right) queue.push(current->right);
        }
        
        result.push_back(level);
      }
      
      return result;
    }
};
  
} // namespace

void testBinaryTreeLevelOrderTraversal() {
}
