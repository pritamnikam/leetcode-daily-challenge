/*
103. Binary Tree Zigzag Level Order Traversal
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> result;
            if (root == nullptr) {
                return result;
            }

            bool leftToRight = true;
            queue< TreeNode*> queue;
            queue.push(root);

            while (!queue.empty()) {
                int size = queue.size();

                deque<int> level;
                for (int i = 0; i < size; ++i) {
                    TreeNode* u = queue.front();
                    queue.pop();

                    if (leftToRight) {
                        level.push_back(u->val);
                    }
                    else {
                        level.push_front(u->val);
                    }

                    if (u->left != nullptr)
                        queue.push(u->left);
                    if (u->right != nullptr)
                        queue.push(u->right);
                }

                result.emplace_back(level.begin(), level.end());
                leftToRight = !leftToRight;
            }
            return result;
        }
    };
}

void testBinaryTreeZigzagOrderTraversal() {
    // Input: root = [3,9,20,null,null,15,7]
    // Output: [[3], [20, 9], [15, 7]]

    TreeNode three(3), nine(9), twenty(20), fifteen(15), seven(7);
    three.left = &nine; three.right = &twenty;
    twenty.left = &fifteen; twenty.right = &seven;

    vector<vector<int>> output = Solution().zigzagLevelOrder(&three);

}
