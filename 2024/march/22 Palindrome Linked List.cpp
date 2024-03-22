// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

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
    ListNode* Reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* next = Reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return next;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return false;

        if (head->next == nullptr)
            return true;

        // 1. find the mid of the list
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHead = nullptr;
        prev->next = nullptr;
        if (fast == nullptr)
            secondHead = slow;  // even
        else
            secondHead = slow->next; // odd

        // 2. reverse the sublist from mid
        secondHead = Reverse(secondHead);

        // 3. if 1st part and second part are matching, it's a Palindrome
        while (head && secondHead) {
            if (head->val != secondHead->val)
                return false;

            head = head->next;
            secondHead = secondHead->next;
        }

        return true;
    }
};
