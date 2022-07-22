/*
86. Partition List
https://leetcode.com/problems/partition-list/

Given the head of a linked list and a value x, partition it such that all nodes less 
than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:
Input: head = [2,1], x = 2
Output: [1,2]

Constraints:
The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200

*/

namespace {

	// Definition for singly-linked list.
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	class Solution
	{
	public:
		ListNode* partition(ListNode* head, int x) {
			// use dummy nodes
			ListNode beforeHead, afterHead, *before, *after;
			beforeHead.next = head;
			afterHead.next = head;
			before = &beforeHead;
			after = &afterHead;

			while (head) {
				if (head->val > x) {
					after->next = head;
					after = after->next;
				}
				else {
					before->next = head;
					before = before->next;
				}

				head = head->next;
			}

			after->next = nullptr;
			before->next = afterHead.next;
			return beforeHead.next;
		}
	};
}

void testPartitionList() {
	ListNode one(1), two(2), three(3), four(4), five(5);
	five.next = &two; three.next = &five; one.next = &three; two.next = &four;
	ListNode* l = Solution().partition(&one, 2);

}
