/*
Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return vector<vector<int>>();

        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* u = q.front();
                q.pop();

                if (leftToRight)
                    currentLevel[i] = u->val;
                else
                    currentLevel[levelSize - i - 1] = u->val;

                if (u->left != nullptr)
                    q.push(u->left);
                if (u->right != nullptr)
                    q.push(u->right);
            }

            result.emplace_back(currentLevel);
            leftToRight = !leftToRight;
        }

        return result;
    }
};



struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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