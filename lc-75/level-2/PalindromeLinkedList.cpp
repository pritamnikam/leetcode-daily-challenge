/*
234. Palindrome Linked List
https://leetcode.com/problems/palindrome-linked-list/

Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false


Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space?
*/


using namespace std;

#include <iostream>

namespace {

    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    class Solution {

        ListNode* reverse(ListNode* head) {
            if (head == nullptr || head->next == nullptr) return head;
            ListNode* p = reverse(head->next);
            head->next->next = head;
            head->next = nullptr;
            return p;
        }

    public:
        bool isPalindrome(ListNode* head) {
            if (head == nullptr || head->next == nullptr) return true;

            // 1. find mid of list
            ListNode* slow = head,
                * fast = head,
                * prev = nullptr;

            while (fast && fast->next) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }

            prev->next = nullptr;
            ListNode* secondHead = slow;
            if (fast != nullptr) {
                secondHead = slow->next;
            }

            // 2. revers the 2nd head
            secondHead = reverse(secondHead);

            // 3. if 1st part and second part are matching, it's a Palindrome
            ListNode* cur = head;
            while (cur && secondHead) {
                if (cur->val != secondHead->val) return false;
                cur = cur->next;
                secondHead = secondHead->next;
            }

            return true;
        }
    };
}

void testIsPalindrome() {
    /*
        Example 1:
        Input: head = [1,2,2,1]
        Output: true
    */

    ListNode l(1);
    l.next = new ListNode(2);
    l.next->next = new ListNode(2);
    l.next->next->next = new ListNode(1);

    cout << "Palindrome Linked List: " << Solution().isPalindrome(&l) << endl;
}
