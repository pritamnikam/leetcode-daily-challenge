// 2807. Insert Greatest Common Divisors in Linked List
// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list 

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head->next == nullptr) {return head;}

        ListNode* cur = head;    
        ListNode* next = head->next;

        while (next != nullptr) {
            int gcd = calculateGCD(cur->val, next->val);
            ListNode* gcdNode = new ListNode(gcd);

            cur->next = gcdNode;
            gcdNode->next = next;

            cur = next;
            next = next->next;
        }    
        return head;
    }
private:
    int calculateGCD(int i, int j) {
        while (j != 0) {
            int temp = j;
            j = i % j;
            i = temp;
        }

        return i;
    }
};
