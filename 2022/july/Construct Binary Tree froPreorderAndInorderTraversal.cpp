/*
105. Construct Binary Tree from Preorder and Inorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and 
inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]

Constraints:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

*/

namespace {
  class Solution {
    int preorderIndex;
    unordered_map<int, int> inorderIndexMap;
    
    TreeNode* arrayToTree(vector<int>& preorder,
                          int left,
                          int right) {
      if (left > right) return nullptr;
      
      // select the preorder_index element as the root and increment it
      int rootValue = preorder[preorderIndex];
      TreeNode* root = new TreeNode;
      root->val = rootValue;
      ++preorderIndex;
      
      root->left = arrayToTree(preorder, 
                               left, 
                               inorderIndexMap[rootValue] - 1);
      
      root->right = arrayToTree(preorder,
                                inorderIndexMap[rootValue] + 1,
                                right);
      return root;
    }
    
    public:
    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {
      if (preorder.empty() || inorder.empty()) {
            return nullptr;
      }
      
      if (preorder.size() != inorder.size()) {
            return nullptr;
      }
      
      /*
        Algorithm:
            1. Build a hashmap |inorderIndexMap| to record the relation of value -> index for inorder, so that we can find the position of root in constant time.
            2. Initialize an integer variable preorderIndex to keep track of the element that will be used to construct the root.
            3. Implement the recursion function arrayToTree which takes a range of inorder and returns the constructed binary tree:
                a. if the range is empty, return null;
                b. initialize the root with preorder[preorderIndex] and then increment preorderIndex;
                c. recursively use the left and right portions of inorder to construct the left and right subtrees.
            4. Simply call the recursion function with the entire range of inorder.
        */
             
        // build a hashmap to store value -> its index relations
        for (int i = 0; i < inorder.size(); ++i) {
          inorderIndexMap[inorder[i]] = i;
        }
      
        preorderIndex = 0;
        int left = 0,
            right = preorder.size() - 1;
        return arrayToTree(preorder, left, right);
    }
  };
} // namespace

void testBuildTree() {
  vector<int> preorder = {3,9,20,15,7}, 
              inorder = {9,3,15,20,7};
  
  TreeNode* root = Solution().buildTree(preorder, inorder);
}

