/*
141. Linked List Cycle

*/
using namespace std;

#include <iostream>

namespace {

struct ListNode {
  int val;
  ListNode* next;
};

class Solution {
public:
  bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;

    ListNode* cur = head, next = head;
    while (next && next->next) {
      next = next->next->next;
      cur = head->next;
      if (cur == next) {
        return true;
      }
    }

    return false;
  }
};
} // namespacce
