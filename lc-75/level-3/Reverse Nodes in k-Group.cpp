/*
25. Reverse Nodes in k-Group
https://leetcode.com/problems/reverse-nodes-in-k-group/

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000


Follow-up: Can you solve the problem in O(1) extra memory space?


*/

using namespace std;
#include <iostream>

namespace {
    struct ListNode {
        int val;
        ListNode* next;

        ListNode() : val(-1), next(nullptr) {}
        ListNode(int val) : val(val), next(nullptr) {}
        ListNode(int val, ListNode* next) : val(val), next(next) {}
    };

    class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (head == nullptr or k <= 1) {
                return head;
            }

            ListNode* current = head;
            ListNode* prev = nullptr;
            ListNode* next = nullptr;
            int count = 0;

            // Make sure we have enough nodes to reverse
            ListNode* temp = head;
            while (temp) {
                temp = temp->next;
                ++count;
            }

            if (count < k) return head;

            // reverse in group
            current = head;
            count = 0;
            while (count != k && current) {
                next = current;
                current->next = prev;
                prev = current;
                current = next;
                ++count;
            }
            // Recurrsively reverse all group of size k
            if (next) {
                head->next = reverseKGroup(next, k);
            }

            return prev;
        }
    };
} // namespace


void testReverseKGroup() {
/*
    Input: head = [1,2,3,4,5], k = 2
    Output: [2,1,4,3,5]
*/

    int k = 2;
    ListNode one(1), two(2), three(3), four(4), five(5);
    one.next = &two; two.next = &three, three.next = &four, four.next = &five;

    ListNode* l = Solution().reverseKGroup(&one, k);
}