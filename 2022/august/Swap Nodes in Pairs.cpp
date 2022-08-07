/*
24. Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed.)

Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]


Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

*/

namespace {
    struct ListNode {
        int val;
        ListNode* next;

        ListNode() : val(-1), next(nullptr) {}
        ListNode(int val) : val(val), next(nullptr) {}
    };

    class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (head == nullptr or head->next == nullptr)
                return head;

            ListNode* current = head;
            ListNode* next = current->next;

            // swap next pointers of current <-> next
            current->next = next->next;
            next->next = current;

            // recurrsion
            if (current->next != nullptr) {
                current->next = swapPairs(current->next);
            }

            return next;
        }
    };
}  // namespace

void testSwapInPair() {
    // Input: head = [1,2,3,4]
    // Output: [2, 1, 4, 3]

    ListNode one(1), two(2), three(3), four(4);
    one.next = &two; two.next = &three; three.next = &four;
    ListNode* result = Solution().swapPairs(&one);

}