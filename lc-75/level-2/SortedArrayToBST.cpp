/*
108. Convert Sorted Array to Binary Search Tree
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.


Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.

*/

using namespace std;

#include <iostream>
#include <vector>


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
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return sortedArrayToBST(nums, 0, nums.size() - 1);
        }

    private:
        TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
            if (l > r)
                return nullptr;

            int mid = l + (r - l) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = sortedArrayToBST(nums, l, mid - 1);
            root->right = sortedArrayToBST(nums, mid + 1, r);
            return root;
        }
    };
}

void testSortedArrayToBST() {
    vector<int> nums = { -10, -3, 0, 5, 9 };
    //    Output: [0, -3, 9, -10, null, 5]

    TreeNode* r = Solution().sortedArrayToBST(nums);
}
