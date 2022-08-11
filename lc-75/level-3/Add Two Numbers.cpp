/*
2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Input: l1 = [0], l2 = [0]
Output: [0]


Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

*/


using namespace std;

namespace {

	struct ListNode {
		int val;
		ListNode* next;

		ListNode() : val(-1), next(nullptr) {}
		ListNode(int val) : val(val), next(nullptr) {}
	};

	class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

			ListNode dummy;
			ListNode* current = &dummy;

			int carry = 0;

			while (l1 || l2 || carry) {
				int i = l1 == nullptr ? 0 : l1->val;
				int j = l2 == nullptr ? 0 : l2->val;
				int sum = i + j + carry;
				carry = sum / 10;

				current->next = new ListNode(sum % 10);
				current = current->next;

				if (l1) l1 = l1->next;
				if (l2) l2 = l2->next;
			}

			return dummy.next;
		}
	};
}  // namespace


void testAddTwoNumbers() {
	// l1 = [2, 4, 3], l2 = [5, 6, 1]
	// [7,0,5]

	ListNode two(2), three(3), four(4), five(5), six(6), one(1);

	ListNode l1 = two; two.next = &four; four.next = &three;
	ListNode l2 = five; five.next = &six; six.next = &one;

	ListNode* sum = Solution().addTwoNumbers(&l1, &l2);

}
