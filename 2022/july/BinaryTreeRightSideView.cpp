/*
199. Binary Tree Right Side View
https://leetcode.com/problems/binary-tree-right-side-view/


Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,null,3]
Output: [1,3]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/

using namespace std;

#include <vector>
#include <queue>
#include <iostream>

namespace {
  class Solution {
    public:
      vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> result;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
          int size = queue.size();
          for (int i = 0 ; i < size; ++i) {
            TreeNode* current = queue.front();
            queue.pop();
            if (size-1 == i)
              result.push_back(current->val);
            
            if (current->left) queue.push(current->left);
            if (current->right) queue.push(current->right);
          }
        }
        
        return result;
      }
  };
}

void testBinaryTreeRightSideView() {
  // [1,2,3,null,5,null,4]
  TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);
  vector<int> result = Solution().rightSideView(root);
  
  cout <<"Right side view: ";
  for (int n: result)
    cout << n << ", ";
  count << endl;
}
