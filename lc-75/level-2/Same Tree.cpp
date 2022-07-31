/*
100. Same Tree
https://leetcode.com/problems/same-tree/

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

*/


using namespace std;

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (p == nullptr && q == nullptr)
                return true;

            if (p == nullptr || q == nullptr)
                return false;

            return (p->val == q->val) &&
                isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right);
        }
    };
}