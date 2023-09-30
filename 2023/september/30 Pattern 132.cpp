// 456. Pattern 132
// https://leetcode.com/problems/132-pattern/description/

using namespace tsd;

#include <iostream>
#include <vector>
#include <stack>

namespace {

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
      int n = nums.size();
      if (n < 3) return false;

      stack<int> stack;
      vector<int> minArray(n);
      minArray[0] = nums[0];

      for (int i = 1; i <n; ++i) {
        minArray[i] = min(minArray[i-1], nums[i]);
      }


      for (int j = n-1; j > 0; --j) {
        while (!stack.empty() && stack.top() < nums[j]) {
          if (stack.top() > minArray[j]) return true;

          stack.pop();
        }

        stack.push(nums[j]);
      }

      return false;
    }
};

} // namespace
