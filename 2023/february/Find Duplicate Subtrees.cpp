/*
652. Find Duplicate Subtrees
https://leetcode.com/problems/find-duplicate-subtrees/description/

Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

Example 1:
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:
Input: root = [2,1,1]
Output: [[1]]

Example 3:
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]

Constraints:
The number of the nodes in the tree will be in the range [1, 5000]
-200 <= Node.val <= 200

*/

using namespace std;

#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

namespace {
    /*
    Definition for a binary tree node.
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
        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
            vector<TreeNode*> vt;
            unordered_map<string, int> map;
            serialize(root, map, vt);
            return vt;
        }

        const char kMarker = '$';
        string serialize(TreeNode* root,
            unordered_map<string, int>& map,
            vector<TreeNode*>& vt) {

            if (root == nullptr) {
                return to_string(kMarker);
            }

            string left = serialize(root->left, map, vt);
            string right = serialize(root->right, map, vt);

            string key = to_string(root->val);
            key += kMarker;
            key += left;
            key += kMarker;
            key += right;

            if (map.count(key) && map[key] == 1) {
                vt.push_back(root);
            }

            map[key]++;
            return key;
        }
    };
} // namespace

void testFindDuplicateSubtree() {
    // Input: root = [1,2,3,4,null,2,4,null,null,4]
    // Output: [[2, 4], [4]]
    TreeNode One(1), two(2), three(3), four(4);
}
