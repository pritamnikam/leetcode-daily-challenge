// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result = {-1, -1};
        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* current = head->next;
        int currentIndex = 1;
        int prevCriticalIndex = 0;
        int firstCriticalIndex = 0;

        while (
            current->next != nullptr
        ) {
            if (
                (current->val < prev->val && current->val < current->next->val) ||
                (current->val > prev->val && current->val > current->next->val)
            ) {
                if (prevCriticalIndex == 0) {
                    prevCriticalIndex = currentIndex;
                    firstCriticalIndex = currentIndex;
                } else {
                    minDistance = min(
                        minDistance,
                        currentIndex - prevCriticalIndex
                    );

                    prevCriticalIndex = currentIndex;
                }
            }
            
            currentIndex++;
            prev = current;
            current = current->next;
        }

        if (minDistance != INT_MAX) {
            int maxDistance = prevCriticalIndex - firstCriticalIndex;
            result = {minDistance, maxDistance};
        }

        return result;
    }
};
