/*
445. Add Two Numbers II
https://leetcode.com/problems/add-two-numbers-ii/description/

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]


Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.


Follow up: Could you solve it without reversing the input lists?


*/

using namespace std;

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

        ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* temp;
            while (head) {
                // Keep the next node.
                temp = head->next;
                // reverse the link
                head->next = prev;
                // Update the previous node and the current node.
                prev = head;
                head = temp;
            }
            return prev;
        }
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* r1 = reverseList(l1);
            ListNode* r2 = reverseList(l2);

            int totalSum = 0;
            int carry = 0;
            ListNode* ans = new ListNode();
            while (r1 || r2) {
                if (r1) {
                    totalSum += r1->val;
                    r1 = r1->next;
                }
                if (r2) {
                    totalSum += r2->val;
                    r2 = r2->next;
                }

                ans->val = totalSum % 10;
                carry = totalSum / 10;
                ListNode* head = new ListNode(carry);
                head->next = ans;
                ans = head;
                totalSum = carry;
            }

            return carry == 0 ? ans->next : ans;
        }
    };
}
