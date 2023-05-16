/*
24. Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]


Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

*/

using namespace std;
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

	class Solution {
        ListNode* swapPairs(ListNode* head) {
            if (head == nullptr || head->next == nullptr)
                return head;

            ListNode* current = head;
            ListNode* next = current->next;

            // swap
            current->next = next->next;
            next->next = current;

            if (current->next != nullptr) {
                current->next = swapPairs(current->next);
            }

            return next;
        }

        /* Recursive function to pairwise swap elements of a linked list */
        void pairWiseSwap(ListNode* head) {
            /* There must be at-least two nodes in the list */
            if (head != nullptr && head->next != nullptr) {

                /* Swap the node's data with data of next node */
                swap(head->val, head->next->val);

                /* Call pairWiseSwap() for rest of the list */
                pairWiseSwap(head->next->next);
            }
        }
	};
}
