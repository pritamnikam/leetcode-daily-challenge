/*
Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome.

Input: head = [1,2,2,1]
Output: true

Input: head = [1,2]
Output: false

Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space?


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
    ListNode* Reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* p = head;
        ListNode* q = head->next;

        q = Reverse(q);
        p->next->next = p;
        p->next = nullptr;
        return q;
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
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* p = head;
        ListNode* q = head->next;

        q = Reverse(q);
        p->next->next = p;
        p->next = nullptr;
        return q;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return false;

        ListNode* p = head, * q = head, * secondHead = head;
        while (p && q) {
            p = p->next;
            if (p)
                p = p->next;

            // even
            if (p == nullptr) {
                secondHead = q->next;
                break;
            }
            // odd
            else if (p->next == nullptr) {
                secondHead = q->next->next;
                break;
            }

            q = q->next;
        }

        q->next = nullptr;
        p = Reverse(secondHead);
        q = head;

        while (p && q) {
            if (p->val != q->val)
                return false;

            p = p->next;
            q = q->next;
        }

        return true;
    }
};