// 590. N-ary Tree Postorder Traversal
// https://leetcode.com/problems/n-ary-tree-postorder-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> output;
        helper(root, output);
        return output;
    }

private:

void helper(Node* root, vector<int>& output) {
    if (root == nullptr) {
        return;
    }

    for (Node* node: root->children) {
        helper(node, output);
    }

    output.push_back(root->val);
}

};
