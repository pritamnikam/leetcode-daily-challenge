// 456. Pattern 132
// https://leetcode.com/problems/132-pattern/description/

using namespace std;

#include <iostream>
#include <vector>
#include <stack>

namespace {

class Solution {
public:
    // Bruit Force: O(n^3)
    bool find132PatternBruitForce(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[k] > nums[i] && nums[j] > nums[k]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    // Bruit Force Improvement: O(n^2)
    bool find132PatternTwoForloops(vector<int>& nums) {
        int min_i = INT_MAX;
        for (int j = 0; j < nums.size() - 1; j++) {
            min_i = min(min_i, nums[j]);
            for (int k = j + 1; k < nums.size(); k++) {
                if (nums[k] < nums[j] && min_i < nums[k]) {
                    return true;
                }
            }
        }

        return false;
    }
    // Bruit Force Improvement: O(n)
    bool find132PatternOneLoop() {
        int length = nums.size();

        // Check if the array has less than 3 elements
        if (length < 3)
            return false;

        // Stack to keep track of decreasing elements.
        stack<int> decreasingStack;

        // Maximum value of the third element in the 132 pattern.
        int maxThirdElement = INT_MIN;

        // Traverse the array from right to left
        for (int i = length - 1; i >= 0; i--) {
            int currentNumber = nums[i];

            // Check for 132 pattern
            if (currentNumber < maxThirdElement)
                return true;  // Found a 132 pattern.

            // Maintain the stack with decreasing elements
            while (!decreasingStack.empty() && decreasingStack.top() < currentNumber) {
                maxThirdElement = decreasingStack.top();
                decreasingStack.pop();
            }

            // Push the current element onto the stack.
            decreasingStack.push(currentNumber);
        }

        return false; // No 132 pattern found
    }

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
