// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }

        ListNode *cur = head;
        ListNode *next = head;
        while (next && next->next) {
            next = next->next->next;
            cur = cur->next;

            if (cur == next)
                return true;
        }

        return false;
    }
};
