/*
Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

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
class Solution {
public:
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                if (head == nullptr) {
                    head = cur = l1;
                }
                else {
                    cur->next = l1;
                    cur = cur->next;
                }

                l1 = l1->next;
            }
            else {
                if (head == nullptr) {
                    cur = head = l2;
                }
                else {
                    cur->next = l2;
                    cur = head->next;
                }

                l2 = l2->next;
            }
        }

        if (l1) {
            cur->next = l1;
        }
        else {
            cur->next = l2;
        }

        return head;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* head = nullptr;
        if (l1->val < l2->val) {
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }
        else {
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }

        return head;
    }
};