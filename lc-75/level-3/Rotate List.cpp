/*
61. Rotate List
https://leetcode.com/problems/rotate-list/

Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Input: head = [0,1,2], k = 4
Output: [2,0,1]


The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

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

    class Solution {
    public:
        ListNode* rotateRight1(ListNode* head, int k) {
            int size = Size(head);
            if (head == nullptr or
                (k = k % size) == 0) {
                return head;
            }

            ListNode* current = head,
                * last = nullptr,
                * newHead = nullptr;

            while (current->next) {
                --k;
                current = current->next;
                if (k == 0) {
                    last = current;
                    newHead = current->next;
                }
            }

            current->next = head;
            last->next = nullptr;
            head = newHead;
            return head;
        }

        int Size(ListNode* head) {
            int size = 0;
            while (head) {
                head = head->next;
                ++size;
            }

            return size;
        }

        ListNode* reverse(ListNode* head) {
            ListNode* current = head;
            ListNode* pred = nullptr;
            while (current) {
                ListNode* next = current->next;
                current->next = pred;
                pred = current;
                current = next;
            }

            return pred;
        }

        ListNode* reverse(ListNode* head, int start, int end) {
            if (start == end)
                return head;

            ListNode* current = head;
            ListNode* pred = nullptr;
            while (start) {
                pred = current;
                current = current->next;
                --start;
            }

            while (end) {
                ListNode* next = current->next;
                current->next = pred;
                pred = current;
                current = next;
                --end;
            }
            return head;
        }


        ListNode* rotateRight(ListNode* head, int k) {
            if (head == nullptr || head->next == nullptr)
                return head;

            int size = Size(head);
            k = (k % size);
            if (k == 0)
                return head;

            // 1. reverse list
            head = reverse(head);

            ListNode* newHead = nullptr;
            int count = k;

            ListNode* current = head;
            ListNode* pred = nullptr;
            ListNode* next = nullptr;
            // 2. reverse sublist 0 to k
            {
                while (count) {
                    next = current->next;
                    current->next = pred;
                    pred = current;
                    current = next;
                    --count;
                }

                newHead = pred;
            }

            // 3. reverse sublist k+1 to end
            {
                pred = nullptr;
                while (current) {
                    next = current->next;
                    current->next = pred;
                    pred = current;
                    current = next;
                }

                head->next = pred;
            }

            return newHead;
        }
    };

} // namespace


void testRotateList() {
    /*
        Input: head = [1,2,3,4,5], k = 2
        Output: [4,5,1,2,3]
    */

    int k = 2;
    ListNode one(1), two(2), three(3), four(4), five(5);
    one.next = &two; two.next = &three, three.next = &four, four.next = &five;

    ListNode* l = Solution().rotateRight(&one, k);
}