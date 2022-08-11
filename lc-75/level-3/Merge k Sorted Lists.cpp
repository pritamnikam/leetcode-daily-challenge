/*
23. Merge k Sorted Lists
https://leetcode.com/problems/merge-k-sorted-lists/

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []


Constraints:
k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

*/

using namespace std;

#include <iostream>
#include <queue>


namespace {
    struct ListNode {
        int val;
        ListNode* next;

        ListNode() : val(-1), next(nullptr) {}
        ListNode(int val) : val(val), next(nullptr) {}
        ListNode(int val, ListNode* next) : val(val), next(next) {}
    };


    struct Compare {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };

    class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            // min heap
            priority_queue<ListNode*,
                vector<ListNode*>,
                Compare> minHeap;

            // add head of all lists to min heap
            for (ListNode* list : lists) {
                if (list)
                    minHeap.push(list);
            }

            // dummy node to handle corner cases
            ListNode* sentinal = new ListNode();
            ListNode* current = sentinal;

            // peak the top of heap as next in the new list
            while (!minHeap.empty()) {
                ListNode* top = minHeap.top();
                minHeap.pop();

                if (top->next != nullptr)
                    minHeap.push(top->next);

                current->next = top;
                current = current->next;
            }

            return sentinal->next;
        }
    };
} // namespace

void testMergeKSortedLists() {
    /*
    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation: The linked-lists are:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    merging them into one sorted list:
    1->1->2->3->4->4->5->6
    
    */

    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));

    vector<ListNode*>lists = { l1, l2, l3 };

    ListNode* l = Solution().mergeKLists(lists);
}
