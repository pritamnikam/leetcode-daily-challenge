/*
543. Diameter of Binary Tree
https://leetcode.com/problems/diameter-of-binary-tree/

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1

Constraints:
The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100

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
        int diameter(TreeNode* root) {
            if (root == nullptr) return 0;

            int treeDiameter = 0;
            calculateHeight(root, treeDiameter);
            return treeDiameter;
        }

    private:
        int calculateHeight(TreeNode* root, int& treeDiameter) {
            if (root == nullptr) return 0;

            int l = calculateHeight(root->left, treeDiameter);
            int r = calculateHeight(root->right, treeDiameter);

            treeDiameter = max(treeDiameter, l + r);
            return 1 + max(l, r);
        }
    };
} // namespace

void testDiameterOfTree() {
    /*
        Input: root = [1,2,3,4,5]
        Output: 3
    */

    TreeNode one(1), two(2), three(3), four(4), five(5);
    one.left = &two; one.right = &three;
    two.left = &four; two.right = &five;

    cout << "Diameter of Binary Tree: " << Solution().diameter(&one) << endl;
}
