/*
106. Construct Binary Tree from Inorder and Postorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder
is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]


Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.


*/

using namespace std;

#include <iostream>
#include <unordered_map>
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
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            unordered_map<int, int> positionMap;

            // fill positions
            fillPositionsMapping(inorder, positionMap);

            // get post order index
            int index = postorder.size() - 1;

            // build recurrsively
            int start = 0, end = index;
            return buildTreeRecurrsively(inorder,
                postorder,
                positionMap,
                start,
                end,
                index);
        }

        TreeNode*
            buildTreeRecurrsively(vector<int>& inorder,
                vector<int>& postorder,
                unordered_map<int, int>& positionMap,
                int start, int end, int& index) {
            if (start > end)
                return nullptr;

            int val = postorder[index];
            int pivot = positionMap[val];
            --index;

            TreeNode* root = new TreeNode(val);

            // right sub tree
            root->right = buildTreeRecurrsively(inorder,
                postorder,
                positionMap,
                pivot + 1,
                end,
                index);
            // left sub tree
            root->left = buildTreeRecurrsively(inorder,
                postorder,
                positionMap,
                start,
                pivot - 1,
                index);
            return root;
        }

    private:
        void fillPositionsMapping(vector<int>& inorder,
            unordered_map<int, int>& positionMap) {
            int i = 0;
            for (int n : inorder) {
                positionMap[n] = i;
                ++i;
            }
        }
    };
}
