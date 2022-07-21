/*
92. Reverse Linked List II
https://leetcode.com/problems/reverse-linked-list-ii/

Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]

Constraints:
The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
*/

using namespace std;

#include <iostream>

namespace {

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

	class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			if (m == 1) {
				return reverseN(head, n);
			}

			head->next = reverseBetween(head->next, m - 1, n - 1);
			return head;
		}

	private:
		ListNode* successor = nullptr;
		ListNode* reverseN(ListNode* head, int n) {
			if (n == 1) {
				successor = head->next;
				return head;
			}

			head->next = reverseN(head->next, n - 1);
			head->next->next = head;
			head->next = successor;
			return head;
		}
	};
}  // namespace

void testReverseList() {
	/*
		Input: head = [1,2,3,4,5], left = 2, right = 4
		Output: [1,4,3,2,5]
	*/

	ListNode one(1), two(2), three(3), four(4), five(5);
	one.next = &two; two.next = &three; three.next = &four; four.next = &five;

	ListNode* l = Solution().reverseBetween(&one, 2, 4);
}
