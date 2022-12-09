/*
1026. Maximum Difference Between Node and Ancestor
https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.



Example 1:


Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
Example 2:


Input: root = [1,null,2,null,0,3]
Output: 3


Constraints:

The number of nodes in the tree is in the range [2, 5000].
0 <= Node.val <= 105
*/

using namespace std;

#include <iostream>


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
        int maxAncestorDiff(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }
            return maxAncestorDiff(root, root->val, root->val);
        }

    private:
        int maxAncestorDiff(TreeNode* node, int curMax, int curMin) {
            // if encounter leaves, return the max-min along the path
            if (node == nullptr) {
                return curMax - curMin;
            }

            //pre-order:
            
            // else, update max and min
            // and return the max of left and right subtrees
            curMax = max(curMax, node->val);
            curMin = min(curMin, node->val);

            int left = maxAncestorDiff(node->left, curMax, curMin);
            int right = maxAncestorDiff(node->right, curMax, curMin);
            return max(left, right);
        }
    };
}

void testMaxDifference() {
    // Input: root = [1,null,2,null,0,3], Output: 3

    TreeNode zero(0), one(1), two(2), three(3);
    one.right = &two; two.right = &zero; zero.left = &three;
    cout << "Maximum Difference Between Node and Ancestor: " << Solution().maxAncestorDiff(&one) << endl;
}
