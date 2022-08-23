/*
234. Palindrome Linked List
https://leetcode.com/problems/palindrome-linked-list/

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
	public:
		bool isPalindrome(ListNode* head) {

			if (head == nullptr) return true;

			ListNode* firstHalfEnd = endOfFirstHalf(head);
			ListNode* secondHaflHead = reverseList(firstHalfEnd->next);

			ListNode* p1 = head;
			ListNode* p2 = secondHaflHead;
			bool result = true;

			while (result
				and p2 != nullptr) {

				if (p1->val != p2->val) {
					result = false;
				}

				p1 = p1->next;
				p2 = p2->next;
			}

			firstHalfEnd->next = reverseList(secondHaflHead);
			return result;
		}

		ListNode* reverseListRecurrsive(ListNode* head) {
			if (head == nullptr
				or head->next == nullptr) {
				return head;
			}

			ListNode* next = reverseListRecurrsive(head->next);
			head->next->next = head;
			head->next = nullptr;
			return next;
		}

		ListNode* reverseList(ListNode* head) {
			if (head == nullptr
				or head->next == nullptr) {
				return head;
			}

			ListNode* current = head;
			ListNode* prev = nullptr;
			ListNode* next = nullptr;

			while (current) {
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}

			return prev;
		}

		ListNode* endOfFirstHalf(ListNode* head) {
			ListNode* slow = head;
			ListNode* fast = head;

			while (fast->next and fast->next->next) {
				slow = slow->next;
				fast = fast->next->next;
			}

			return slow;
		}

	};
}
