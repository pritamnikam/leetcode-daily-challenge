/*
109. Convert Sorted List to Binary Search Tree
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree


Given the head of a singly linked list where elements are sorted in ascending order, convert it to a
height-balanced
 binary search tree.



Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []


Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105

*/

using namespace std;

#include <vector>
#include <iostream>


namespace {
    /**
 * Definition for singly-linked list.
 */ 
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
 
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
        TreeNode* sortedArrayToBST(vector<int>& nums, int lo, int hi) {
            if (lo > hi)
                return nullptr;

            int mid = lo + (hi - lo) / 2;
            TreeNode* t = new TreeNode(nums[mid]);
            t->left = sortedArrayToBST(nums, lo, mid - 1);
            t->right = sortedArrayToBST(nums, mid + 1, hi);
            return t;
        }

        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return sortedArrayToBST(nums, 0, nums.size() - 1);
        }

    public:
        TreeNode* sortedListToBST(ListNode* head) {
            vector<int> nums;
            while (head) {
                nums.push_back(head->val);
                head = head->next;
            }

            return sortedArrayToBST(nums);
        }
    };
} // namespace


void testConvertSortedListToBinarySearchTree() {
    /*
        Input: head = [-10,-3,0,5,9]
        Output: [0,-3,9,-10,null,5]
        Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
    */

    ListNode minusTen(-10), minusThree(-3), zero(0), five(5), nine(9);
    minusTen.next = &minusThree; minusThree.next = &zero; zero.next = &five; five.next = &nine;
    TreeNode* t = Solution().sortedListToBST(&minusTen);
}

