/*
328. Odd Even Linked List
https://leetcode.com/problems/odd-even-linked-list/

Given the head of a singly linked list, group all the nodes with odd indices together
followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

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
		ListNode* oddEvenList(ListNode* head) {
			ListNode* odd = head;
			ListNode* even = odd->next;
			ListNode* evenHead = even;

			while (even and even->next) {
				odd->next = even->next;
				odd = odd->next;

				even->next = odd->next;
				even = even->next;
			}

			odd->next = evenHead;
			return head;
		}
	};
}

void testOddEvenList() {
/*
	head = [1,2,3,4,5]
	Output: [1,3,5,2,4]
*/

	ListNode one(1), two(2), three(3), four(4), five(5);
	one.next = &two; two.next = &three; three.next = &four; four.next = &five;

	ListNode* l = Solution().oddEvenList(&one);
}
