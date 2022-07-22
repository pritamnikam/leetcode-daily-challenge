/*
437. Path Sum III
https://leetcode.com/problems/path-sum-iii/

Given the root of a binary tree and an integer targetSum, return the number of paths 
where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards
(i.e., traveling only from parent nodes to child nodes).

Example 1:
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3

Constraints:
The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000

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
        int pathSum1(TreeNode* root, int targetSum) {
            vector<int> currentPath;
            return countPathsRecursive(root, targetSum, currentPath);
        }

    private:
        int countPathsRecursive(TreeNode* currentNode,
            int S,
            vector<int>& currentPath) {

            if (currentNode == nullptr) return 0;

            // add the current node to the path
            currentPath.push_back(currentNode->val);
            int pathCount = 0, sum = 0;

            // find the sums of all sub-paths in the current path list
            for (vector<int>::reverse_iterator itr = currentPath.rbegin();
                itr != currentPath.rend();
                ++itr) {

                sum += *itr;
                if (sum == S) {
                    ++pathCount;
                }
            }

            // traverse the left sub-tree
            pathCount += countPathsRecursive(currentNode->left, S, currentPath);

            // traverse the right sub-tree
            pathCount += countPathsRecursive(currentNode->right, S, currentPath);

            // remove the current node from the path to backtrack,
            // we need to remove the current node while we are going up the recursive call stack.
            currentPath.pop_back();
            return pathCount;
        }



        int pathSum(TreeNode* root, int targetSum) {
            if (root == nullptr) return 0;
            return sumUp(root, 0, targetSum) +
                    pathSum(root->left, targetSum) +
                    pathSum(root->right, targetSum);
        }

        int sumUp(TreeNode* root, int pre, int targetSum) {
            if (root == nullptr) return 0;
            int current = pre + root->val;
            return (current == targetSum) +
                    sumUp(root->left, current, targetSum) +
                    sumUp(root->right, current, targetSum);
        }
    };
} // namesapce
