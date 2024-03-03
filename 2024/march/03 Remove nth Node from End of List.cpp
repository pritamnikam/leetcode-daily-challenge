// 19. Remove nth Node from End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        ListNode* first = dummy;
        ListNode* second = dummy;
        dummy->next = head;

        // move forward n + 1 position
        for (int i = 0; i <= n; i++) first = first->next;

        // maintain n distance
        while (first) {
            first = first->next;
            second = second->next;
        }

        // unlink nth node
        second->next = second->next->next;
        return dummy->next;
    }
};
