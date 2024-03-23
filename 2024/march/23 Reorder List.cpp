// 143. Reorder List
// https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        // base case:
        if (head == nullptr) {
            return;
        }

        // find the mid of the list: 2-pointers
        ListNode* temp = head, *half = head, *prev = nullptr;
        while (temp && temp-> next && temp->next->next) {
            temp = temp->next->next;
            half = half->next;
        }

        // check for event length
        if (temp->next) {
            half = half->next;
        }

        // reverse second half
        while (half) {
            temp = half->next;
            half->next = prev;
            prev = half;
            half = temp;
        }
        half = prev;

        // merge lists
        while (head && half) {
            temp = head->next;
            prev = half->next;

            head->next = half;
            half->next = temp;
            
            head = temp;
            half = prev;
        }

        // closing when length is even
        if (head && head->next) {
            head->next->next = nullptr;
        }
    }
};
