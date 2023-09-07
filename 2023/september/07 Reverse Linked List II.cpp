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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Empty list
        if (head == nullptr) {
            return nullptr;
        }

        // Move the two pointers until they reach the proper starting point
        // in the list.
        ListNode* cur = head, *prev = nullptr;
        while (left > 1) {
            prev = cur;
            cur = cur->next;
            left--;
            right--;
        }

        // The two pointers that will fix the final connections.
        ListNode* con = prev, *tail = cur;

        // Iteratively reverse the nodes until n becomes 0.
        ListNode* third = nullptr;
        while (right > 0) {
            third = cur->next;
            cur->next = prev;
            prev = cur;
            cur = third;
            right--;
        }

        // Adjust the final connections as explained in the algorithm
        if (con != nullptr) {
            con->next = prev;
        } else {
            head = prev;
        }

        tail->next = cur;
        return head;
    }
};
