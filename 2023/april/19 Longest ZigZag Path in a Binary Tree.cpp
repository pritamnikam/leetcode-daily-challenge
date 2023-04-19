/*
1372. Longest ZigZag Path in a Binary Tree
https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.



Example 1:


Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
Example 2:


Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
Example 3:

Input: root = [1]
Output: 0


Constraints:

The number of nodes in the tree is in the range [1, 5 * 104].
1 <= Node.val <= 100


*/

using namespace std;

#include <iostream>
#include <algorithm>

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
    
        int maxLength = 0;

        void solve(TreeNode* root, int dir, int currLength) {
            if (!root) return;
            maxLength = max(maxLength, currLength);
            solve(root->left, 0, dir ? currLength + 1 : 1);
            solve(root->right, 1, dir ? 1 : currLength + 1);
        }
    public:
        int longestZigZag(TreeNode* root) {
            solve(root, 0, 0);
            solve(root, 1, 0);
            return maxLength;
        }
    };
}

void testLongestZigZagPathInBinaryTree() {
    TreeNode one(1), two(2), three(3), four(4), five(5);
    one.left = &two, one.right = &three;
    two.right = &four, four.left = &five;

    cout << "Longest ZigZag Path in a Binary Tree: " << Solution().longestZigZag(&one) << endl;
}
