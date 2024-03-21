// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      // base case
      if (
        head == nullptr ||
        head->next == nullptr
      ) { return head; }

      // recursively get the reverse of the next node
      ListNode* next = reverseList(head->next);
      
      //Adjust the pointer positions
      head->next->next = head;
      head->next = nullptr;
      return next;
    }
};

