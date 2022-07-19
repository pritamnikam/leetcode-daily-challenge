/*
148. Sort List
https://leetcode.com/problems/sort-list/

Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []

Constraints:
The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
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
	public:
		ListNode* sortList(ListNode* head) {
			// merge sort
			return MergeSort(head);
		}

	private:
		ListNode* MergeSort(ListNode* head) {
			if (head == nullptr or head->next == nullptr) return head;

			// find middle node
			ListNode* mid = Middle(head);
			ListNode* next = mid->next;
			mid->next = nullptr;

			// recurrsively merge sort first half
			ListNode* l1 = MergeSort(head);

			// recurrsively merge sort second half
			ListNode* l2 = MergeSort(next);

			// Merge
			return Merge(l1, l2);
		}

		ListNode* Merge(ListNode* l1, ListNode* l2) {
			if (l1 == nullptr) return l1;
			if (l2 == nullptr) return l2;

			ListNode dummy;
			ListNode* cur = &dummy;

			while (l1 and l2) {
				if (l1->val < l2->val) {
					cur->next = l1;
					l1 = l1->next;
				}
				else {
					cur->next = l2;
					l2 = l2->next;
				}

				cur = cur->next;
			}

			cur->next = (l1 != nullptr) ? l1 : l2;
			return dummy.next;
		}

		ListNode* Middle(ListNode* head) {
			ListNode* slow = head, * fast = head->next;
			while (fast and fast->next) {
				fast = fast->next->next;
				slow = slow->next;
			}

			return slow;
		}
	};
}

void testSortList() {
	/*
		head = [4,2,1,3]
		Output: [1,2,3,4]
	*/
	ListNode one(1), two(2), three(3), four(4), five(5);
	four.next = &two; two.next = &one; one.next = &three; three.next = &five;

	ListNode* l = Solution().sortList(&four);
}
