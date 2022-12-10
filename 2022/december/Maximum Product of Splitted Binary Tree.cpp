/*
1339. Maximum Product of Splitted Binary Tree
https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

Given the root of a binary tree, split the binary tree into two subtrees by 
removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer 
may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after
taking it.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. 
Their product is 110 (11*10)

Example 2:
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

Constraints:

The number of nodes in the tree is in the range [2, 5 * 104].
1 <= Node.val <= 104

*/

using namespace std;

#include <iostream>


namespace {

    static int MOD = 1e9 + 7;

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
        int maxProduct(TreeNode* root) {
            totalTreeSum = SumUnder(root);
            SumUnder(root);
            return result % MOD;
        }

    private:
        long long totalTreeSum = 0, 
            result = 0;
        

        long long SumUnder(TreeNode* root) {
            if (root == nullptr) return 0;

            // Get the sum of current subtree.
            long long sum = root->val
                + SumUnder(root->left)
                + SumUnder(root->right);

            // Get the max product after making current subtree as a separate tree
            result = max(
                result, 
                sum * (totalTreeSum - sum));

            return sum;
        }
    };
}  // namespace

void testMaximumProductOfSplittedBinaryTree() {
    // Input: root = [1,2,3,4,5,6], Output: 110
    TreeNode one(1), two(2), three(3), four(4), five(5), six(6);
    one.left = &two, one.right = &three;
    two.left = &four, two.right = &five;
    three.left = &six;

    cout << "Maximum Product of Splitted Binary Tree: " << Solution().maxProduct(&one) << endl;

}
