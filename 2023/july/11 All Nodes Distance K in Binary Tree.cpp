/*
863. All Nodes Distance K in Binary Tree
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:
Input: root = [1], target = 1, k = 3
Output: []

Constraints:
The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000


*/



using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace {
/*
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
        vector<int> res;
        unordered_map<TreeNode*, TreeNode*> parent;
    public:
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            unordered_set<TreeNode*> visited;
            dfs(root, nullptr);
            findNode(target, k, visited);
            return res;
        }

    private:
        void dfs(TreeNode* curr, TreeNode* pre) {
            if (curr != nullptr) {
                parent[curr] = pre;
                dfs(curr->left, curr);
                dfs(curr->right, curr);
            }
        }

        void findNode(TreeNode* curr, int k, unordered_set<TreeNode*>& visited) {
            if (k == 0 && curr != nullptr && visited.find(curr) != visited.end()) {
                res.push_back(curr->val);
                visited.insert(curr);
                return;
            }
            if (k < 0 || curr == nullptr || visited.find(curr) != visited.end()) {
                return;
            }
            visited.insert(curr);
            findNode(curr->left, k - 1, visited);
            findNode(curr->right, k - 1, visited);
            findNode(parent[curr], k - 1, visited);
        }

    };

}  // namespace
