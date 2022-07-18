/*
19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode dummy;
			ListNode* first = &dummy;
			ListNode* second = &dummy;
			dummy.next = head;

			for (int i = 0; i <= n; ++i)
				first = first->next;

			while (first) {
				first = first->next;
				second = second->next;
			}

			second->next = second->next->next;
			return dummy.next;
		}
	};
}

void testRemoveNthFromEnd() {
	/*
		Input: head = [1,2,3,4,5], n = 2
		Output: [1,2,3,5]
	*/
	ListNode one(1), two(2), three(3), four(4), five(5);
	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;

	cout << "Remove Nth Node From End of List" << endl;
	ListNode* head = Solution().removeNthFromEnd(&one, 2);
}
