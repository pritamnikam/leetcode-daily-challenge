/*
Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]


Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct LinkedList {
    ListNode* first = nullptr;
    ListNode* current = nullptr;
    void append(int num) {
        ListNode* t = new ListNode(num);
        if (first == nullptr) {
            first = current = t;
        }
        else {
            current->next = t;
            current = t;
        }
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        LinkedList l;
        int carry = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum / 10;
            l.append(sum);

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int sum = l1->val + carry;
            carry = sum / 10;
            sum = sum / 10;
            l.append(sum);

            l1 = l1->next;
        }

        while (l2) {
            int sum = l2->val + carry;
            carry = sum / 10;
            sum = sum / 10;
            l.append(sum);

            l2 = l2->next;
        }

        if (carry) {
            l.append(carry);
        }

        return l.first;
    }
    
};

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while (l1 && l2) {
            int sum = carry + (l1->val + l2->val);
            carry = sum / 10;
            sum = sum % 10;
            ListNode* cur = new ListNode(sum);
            if (head == nullptr)
                head = tail = cur;
            else {
                tail->next = cur;
                tail = tail->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int sum = carry + (l1->val);
            carry = sum / 10;
            sum = sum % 10;
            ListNode* cur = new ListNode(sum);
            if (head == nullptr)
                head = tail = cur;
            else {
                tail->next = cur;
                tail = tail->next;
            }

            l1 = l1->next;
        }

        while (l2) {
            int sum = carry + (l2->val);
            carry = sum / 10;
            sum = sum % 10;
            ListNode* cur = new ListNode(sum);
            if (head == nullptr)
                head = tail = cur;
            else {
                tail->next = cur;
                tail = tail->next;
            }

            l2 = l2->next;
        }

        if (carry) {
            ListNode* cur = new ListNode(carry);
            tail->next = cur;
            tail = tail->next;
        }

        return head;
    }
};