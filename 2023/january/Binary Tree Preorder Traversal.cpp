/*
144. Binary Tree Preorder Traversal
https://leetcode.com/problems/binary-tree-preorder-traversal/

Given the root of a binary tree, return the preorder traversal of its nodes' values.



Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


Follow up: Recursive solution is trivial, could you do it iteratively?


*/

using namespace std;

#include <iostream>
#include <vector>

namespace {

 /**
 * Definition for a binary tree node.
 */ 
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
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> answer;
            visit(root, answer);
            return answer;
        }

        void visit(TreeNode* root, vector<int>& answer) {
            if (root == nullptr)
                return;

            answer.push_back(root->val);
            visit(root->left, answer);
            visit(root->right, answer);
        }
    };

}  // namespace

void testBinaryTreePreorderTraversal() {
    // root = [1,null,2,3], Output: [1, 2, 3]
    TreeNode one(1), two(2), three(3);
    one.right = &two, two.left = &three;
    vector<int> vt = Solution().preorderTraversal(&one);
}
