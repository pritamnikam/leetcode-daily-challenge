/*
Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Input: preorder = [-1], inorder = [-1]
Output: [-1]

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.


Complexity analysis

Let NN be the length of the input arrays.

Time complexity : O(N)O(N).

Building the hashmap takes O(N)O(N) time, as there are NN nodes to add, and adding items to a hashmap has a cost of O(1)O(1), so we get N \cdot O(1) = O(N)N⋅O(1)=O(N).

Building the tree also takes O(N)O(N) time. The recursive helper method has a cost of O(1)O(1) for each call (it has no loops), and it is called once for each of the NN nodes, giving a total of O(N)O(N).

Taking both into consideration, the time complexity is O(N)O(N).

Space complexity : O(N)O(N).

Building the hashmap and storing the entire tree each requires O(N)O(N) memory. The size of the implicit system stack used by recursion calls depends on the height of the tree, which is O(N)O(N) in the worst case and O(\log N)O(logN) on average. Taking both into consideration, the space complexity is O(N)O(N).


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


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};


using namespace std;

#include <unordered_map>

class Solution {
    int preorderIndex;
    unordered_map<int, int> inorderIndexMap;

    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        // if there are no elements to construct the tree
        if (left > right) return nullptr;

        // select the preorder_index element as the root and increment it
        int rootValue = preorder[preorderIndex];
        TreeNode* root = new TreeNode;
        root->val = rootValue;
        ++preorderIndex;

        // build left and right subtree
        // excluding inorderIndexMap[rootValue] element because it's the root
        root->left = arrayToTree(preorder, left, inorderIndexMap[rootValue] - 1);
        root->right = arrayToTree(preorder, inorderIndexMap[rootValue] + 1, right);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        if (preorder.size() != inorder.size()) {
            return nullptr;
        }

        /*
        Algorithm:

            1. Build a hashmap to record the relation of value -> index for inorder, so that we can find the position of root in constant time.
            2. Initialize an integer variable preorderIndex to keep track of the element that will be used to construct the root.
            3. Implement the recursion function arrayToTree which takes a range of inorder and returns the constructed binary tree:
                a. if the range is empty, return null;
                b. initialize the root with preorder[preorderIndex] and then increment preorderIndex;
                c. recursively use the left and right portions of inorder to construct the left and right subtrees.
            4. Simply call the recursion function with the entire range of inorder.

        */

        preorderIndex = 0;

        // build a hashmap to store value -> its index relations
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        return arrayToTree(preorder, 0, preorder.size() - 1);
    }

    
};

class Solution {
    int preorderIndex;
    Map<Integer, Integer> inorderIndexMap;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        preorderIndex = 0;
        // build a hashmap to store value -> its index relations
        inorderIndexMap = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            inorderIndexMap.put(inorder[i], i);
        }

        return arrayToTree(preorder, 0, preorder.length - 1);
    }

    private TreeNode arrayToTree(int[] preorder, int left, int right) {
        // if there are no elements to construct the tree
        if (left > right) return null;

        // select the preorder_index element as the root and increment it
        int rootValue = preorder[preorderIndex++];
        TreeNode root = new TreeNode(rootValue);

        // build left and right subtree
        // excluding inorderIndexMap[rootValue] element because it's the root
        root.left = arrayToTree(preorder, left, inorderIndexMap.get(rootValue) - 1);
        root.right = arrayToTree(preorder, inorderIndexMap.get(rootValue) + 1, right);
        return root;
    }
}