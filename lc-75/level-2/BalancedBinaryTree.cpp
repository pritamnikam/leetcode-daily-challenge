/*
110. Balanced Binary Tree
https://leetcode.com/problems/balanced-binary-tree/

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104

*/


using namespace std;
#include <iostream>

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
        bool isBalanced(TreeNode* root) {
            if (root == nullptr)
                return root;

            bool l = isBalanced(root->left);
            bool r = isBalanced(root->right);

            int leftHeight = height(root->left);
            int rightHeight = height(root->right);

            return l and r and abs(leftHeight - rightHeight) <= 1;
        }

    private:
        int height(TreeNode* root) {
            if (root == nullptr) return 0;
            return  1 + max(
                            height(root->left),
                            height(root->right)
                        );   
        }
    };
} // namesapce

void testBalanceBinaryTree() {
/*
    Input: root = [3,9,20,null,null,15,7]
    Output: true
*/

    TreeNode three(3), nine(9), twenty(20), fifteen(15), seven(7);
    three.left = &nine; three.right = &twenty;
    twenty.left = &fifteen; twenty.right = &seven;

    cout << "Balanced Binary Tree: " << Solution().isBalanced(&three) << endl;

}
