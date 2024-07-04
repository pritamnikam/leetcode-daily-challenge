// 2181. Merge Nodes in Between Nodes
// https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head) {
        // go to the next of the head
        head = head->next;
        if (head == nullptr) {
            return nullptr;
        }

        int sum = 0;
        ListNode* temp = head;
        while (temp->val != 0) {
            sum += temp->val;
            temp = temp->next;
        }

        head->val = sum;
        head->next = mergeNodes(temp);
        return head;
    }
};
