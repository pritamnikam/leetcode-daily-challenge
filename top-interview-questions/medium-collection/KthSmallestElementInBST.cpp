/*
Kth Smallest Element in a BST

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Input: root = [3,1,4,null,2], k = 1
Output: 1

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and 
you need to find the kth smallest frequently, how would you optimize?

the time complexity of these operations is O(H)O(H), where HH is a height of the binary tree. H = \log NH=logN for the balanced tree and H = NH=N for a skewed tree.

Hence without any optimisation insert/delete + search of kth element has O(2H + k)O(2H+k) complexity. How to optimise that?

That's a design question, basically we're asked to implement a structure which contains a BST inside and optimises the following operations :

Insert

Delete

Find kth smallest

Seems like a database description, isn't it? Let's use here the same logic as for LRU cache design, and combine an indexing structure (we could keep BST here) with a double linked list.

Such a structure would provide:

O(H)O(H) time for the insert and delete.

O(k)O(k) for the search of kth smallest.

bla

The overall time complexity for insert/delete + search of kth smallest is O(H + k)O(H+k) instead of O(2H + k)O(2H+k).

Complexity Analysis

Time complexity for insert/delete + search of kth smallest: O(H + k)O(H+k), where HH is a tree height. O(\log N + k)O(logN+k) in the average case, O(N + k)O(N+k) in the worst case.

Space complexity : O(N)O(N) to keep the linked list.


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
    vector<int> result;

    void Inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        Inorder(root->left);
        result.emplace_back(root->val);
        Inorder(root->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        Inorder(root);
        return result[k - 1];
    }
};