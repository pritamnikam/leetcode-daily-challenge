// 1110 Delete Nodes and Return Forest
// https://leetcode.com/problems/delete-nodes-and-return-forest/

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        root = process(root, toDeleteSet, forest);
        if (root) {
            forest.push_back(root);
        }
        return forest;
    }

private:
TreeNode* process(
    TreeNode* root,
    unordered_set<int>& toDeleteSet,
    vector<TreeNode*>& forest
) {
    if (!root) { return nullptr;}

    root->left = process(root->left, toDeleteSet, forest);
    root->right = process(root->right, toDeleteSet, forest);

    // node evaluate
    if (
        toDeleteSet.find(root->val) != toDeleteSet.end()
    ) {
        if (root->left) {
            forest.push_back(root->left);
        }

        if (root->right) {
            forest.push_back(root->right);
        }

        delete root;
        return nullptr;
    }
    return root;
}
};
